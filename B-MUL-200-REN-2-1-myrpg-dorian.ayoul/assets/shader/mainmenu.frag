#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform vec2 resolution;

#define iTime time/2.
#define iResolution resolution

#define get_rand_frac(x) \
    (fract(sin(dot(x, vec2(12.9898, 4.1414))) * 43758.5453))

#define mod289(x) \
    (x - floor(x * (1.0 / 289.0)) * 289.0)

#define FOG_DST 300.

float hash_vec1(vec2 bvec)
{
    float hash;

    vec3 vec = fract(vec3(bvec.xyx) * .1031);
    vec = vec + dot(vec, vec.yzx + 19.19);
    hash = vec.z * (vec.x + vec.y);
    return fract(hash);
}

float get_noise(in vec2 x)
{
    vec2 vecp = floor(x);
    vec2 vecf = fract(x);
    vecf = vecf * vecf * (1.0 * vecf);
    float hvecp = hash_vec1(vecp);
    float vecy = hash_vec1(vecp + vec2(1.0, 0.0).xy);
    float mixvecp = mix(hvecp, vecy, vecf.x);
    float xhash = hash_vec1(vec2(1.0, 0.0).yx + vecp);
    float mixvecf = mix(xhash, hash_vec1(vec2(1.0, 0.0).xx + vecp), vecf.x);

    return mix(mixvecp, mixvecf, vecf.y);
}

float get_nnoise(vec2 p)
{
    vec2 ip = floor(p);
    vec2 vp = fract(p);
    vp = vp * vp * vp;

    float res = mix(
        mix(get_rand_frac(ip), get_rand_frac(ip + vec2(1.0,0.0)), vp.x),
        mix(get_rand_frac(ip+vec2(0.0,1.0)), get_rand_frac(ip+vec2(1.0,1.0)), vp.x), vp.y);
    return res*res;
}

vec4 perm(vec4 x)
{
    return mod289(((x * 34.0) + 1.0) * x);
}

float snoise(vec3 p)
{
    vec3 a = floor(p);
    vec3 d = p - a;
    d = d * d * (3.0 - 2.0 * d);

    vec4 b = a.xxyy + vec4(0.0, 1.0, 0.0, 1.0);
    vec4 k1 = perm(b.xyxy);
    vec4 k2 = perm(k1.xyxy + b.zzww);

    vec4 c = k2 + a.zzzz;
    vec4 k3 = perm(c);
    vec4 k4 = perm(c + 1.0);

    vec4 o1 = fract(k3 * (1.0 / 41.0));
    vec4 o2 = fract(k4 * (1.0 / 41.0));

    vec4 o3 = o2 * d.z + o1 * (1.0 - d.z);
    vec2 o4 = o3.yw * d.x + o3.xz * (1.0 - d.x);

    return (o4.y * d.y + o4.x * (1.0 - d.y));
}

float terrain(vec2 st)
{
    const float LOOP = 5.;
    float atm = 2.;
    float f = .3;
    float offset = 2.4;
    float h = 0.;

    for (float i= 0.; i < LOOP; i++) {
        h += atm * get_noise(f * st + offset);
        st = mat2(1.12, 0.1531, -.1131, 1.1623) * st;
        atm *= .5;
        f *= 2.5;
        offset *= 2.;
    }
    return h;
}

float water(vec2 st)
{
    const float LOOP = 5.;
    float atm = .1;
    float f = 1.15;
    float off = 2.4;
    float h = 0.;

    for (float i = 0.; i < LOOP; i++, off *= 2.) {
        h += atm * get_nnoise(f * st + off + .8 * iTime);
        atm *= .5;
        f *= 2.;
    }
    return (h);
}

float cloud(vec3 p)
{
    vec2 st = p.xz;
    const float LOOP = 3.;
    float atm = .15;
    float f = .55;
    float offset = 2.4;
    float h= 0.;

    for (float i = 0.; i < LOOP; i++) {
        h += atm * get_nnoise(f * st + offset + .0 * iTime / 2.);
        atm *= .5;
        f *= 2.;
        offset *= 2.;
        st = mat2(1.12, 0.3531, -.2131, 1.4623) * st;
    }
    return h;
}

float curve(float x)
{
    float frequency = .8;
    float atm = .9;
    float value = 0.;

    for (float i= 0.; i < 2.; i++) {
        value += atm * sin(frequency * x + 3.);
        atm *= .5;
        frequency *= 2.;
    }
    return value;
}

float calc_view(float x)
{
    return (0.9 * cos(.8 * x + 3.) * .8 + .9
        * .5 * cos(.8 * 2. * x + 3.) * 2. * .8);
}

float nearest_rivertile(float a, float b, float x, float width)
{
    float nearest = FOG_DST;
    float z;
    float dst;

    for (float jtr = 0.; jtr < 3.; jtr++) {
        z = a + (b - a) / 50. * jtr;
        dst = length(vec2(x - curve(z), b - z));
        nearest = min(nearest, dst - width);
        if (nearest < 0.)
            return (nearest);
    }
    return (nearest);
}

float collides_river(vec3 pos)
{
    float z = pos.z;
    float fw = .1 * sin(z) + .05 * sin(.5 * z) +.6;

    return nearest_rivertile(z - fw, z, pos.x, fw);
}

vec2 map(vec3 pos)
{
    float riv_intersect = collides_river(pos);
    float ter_xz = terrain(pos.xz);
    float type = 3.;

    ter_xz *= smoothstep(0.3, 1.5, riv_intersect);

    if (ter_xz < 0.001) {
        type = 4.;
        ter_xz = water(pos.xz);
    }
    return vec2(ter_xz, type);
}

vec2 get_map_vector(vec3 vec)
{
    float terr = terrain(vec.xz);
    float riverx = collides_river(vec);

    terr = terr * smoothstep(0.3, 1.5, riverx);
    if (terr < 0.001)
        return vec2(0.0, 4.);
    return vec2(terr, 3.);
}

vec3 compute_normalized(vec3 vec, float type)
{
    vec3 result = vec3(0.);
    vec2 normalized = vec2(1., -1.) * 0.5773 * 0.0005;

    return normalize(
            map(normalized.xyy + vec).x * normalized.xyy +
            map(normalized.yyx + vec).x * normalized.yyx +
            map(normalized.yxy + vec).x * normalized.yxy +
            map(normalized.xxx + vec).x * normalized.xxx
    );
}

vec4 castTerrain(vec3 vec, vec3 rd)
{
    float dist = 0.01;
    vec4 result = vec4(0.);

    for (int i = 0; i < 50; ++i) {
        vec3 target = vec + dist * rd;
        vec2 map = get_map_vector(target);
        float h = map.x;
        float delta = target.y - h;

        if (delta < .01)
            return vec4(dist, map.y, 1., h);
        if (dist > FOG_DST) {
            result = vec4(dist, map.y, 0., 0.);
            break;
        }
        dist += .27 * abs(delta) + max(.002 * abs(dist), .05);
    }
    return result;
}

vec4 handle_object_dist(vec3 vec, vec3 rd)
{
    float dst = 0.0;
    vec4 result = vec4(0.0);
    vec2 map;
    float h;
    float z;

    for (float i = 0.; i < 150.; i++) {
        map = map(vec + dst * rd);
        h = map.x;
        z = (vec + dst * rd).y - h;
        if (z < 0.02)
            return (vec4(dst, map.y, 1., h));
        if (dst > FOG_DST) {
            result = vec4(dst, map.y, 0.0, 0.0);
            break;
        }
        dst += 0.19 * abs(z) + max(0.002 * abs(dst), 0.001);
    }
    return (result);
}

// Find sky vec for drawing
vec3 draw_sky(vec3 basevec)
{
    float gencloud = cloud(basevec);
    vec3 col = (vec3(1.) * gencloud) + vec3(0.4431, 0.6353, 0.9882);

    return (col);
}

vec3 get_tercol(vec3 p)
{
    vec3 res = vec3(0.4863, 0.451, 0.3765);
    vec3 coords = p.xyz * 11.76;
    float rn = snoise(coords);
    float rockn = snoise(p.xyz);
    float baseN = .5;
    float stepN = 0.1;
    float wheight = p.y;
    float hasTree = 1. -smoothstep(rn +.4, rn + .4 + .8 * rn, wheight);
    float dwater = 1. -smoothstep(.01 + .1 * rn, .01 + .1 * rn + .08, wheight);
    float dark = snoise(p.xyz);
    float snow = smoothstep(2.5, 3.0, wheight);

    res += dwater * vec3(0.6471, 0.5333, 0.3686);
    res += (1. - dwater) * hasTree * vec3(0.0078, 0.2392, 0.0078);
    res += snow * vec3(1.);
    return res;
}

vec3 render(vec3 vec, vec3 rd)
{
    vec4 castResult = handle_object_dist(vec, rd);
    vec3 lin = vec3(0.);
    vec3 res = vec3(0.4863, 0.451, 0.3765);
    vec3 normal = vec3(0., 0. ,0.);
    float dist = FOG_DST;
    vec3 speNormal = normal;
    float ks = 1.;
    float br = 1.;
    float difR = 0.4;
    float waterR = 0.;
    vec3 p = castResult.x * rd + vec;

    if (castResult.z > 0.) {
        normal = compute_normalized(p,castResult.y);
        speNormal = normal;
        dist = castResult.x;
    }
    if (abs(castResult.y - 4.) < 0.01) {
        res = vec3(0.1608, 0.3804, 0.3569);
        br = 40.;
        difR = .7;
        waterR = 1.;
        ks = 2.;
        speNormal = vec3(0., 1., 0.);
        vec3 red = rd + vec3(0., -(rd.y) * 2., 0.);
        red = normalize(red);
        vec3 from = p +.1 * normal;
        vec4 castRes = castTerrain(from, red);
        if (castRes.z > 0.) {
            if (abs(castRes.y - 3.) < 0.01) {
                vec3 rP = from + castRes.x * red;
                vec3 reCol = get_tercol(rP);
                res = res * .8 + .2 * reCol;
            }
        } else {
            res = res * .7 + .3 * draw_sky(red);
        }
        float castRiver = collides_river(p);
        float width = -castRiver;
        res -= vec3(.4) * smoothstep(0., 0.6, width);
    }
    else if (abs(castResult.y - 3.) < 0.01) {
        ks=0.1;
        res = get_tercol(p);
    }

    vec3 light = normalize(vec3(-0.02, 0.2, 0.3));
    vec3 hal = normalize(light - rd);
    float dif = clamp(dot(normal, light), 0., 1.);
    float spe = pow(clamp(dot(speNormal,hal),0.,1.), br);
    spe *= dif;
    spe *= 0.14 + 0.96 * pow(clamp(1. -dot(hal, light), 0., 1.), 5.);
    vec3 suncol = vec3(0.9686, 0.9216, 0.7922);
    lin += difR * res + res * .7 * dif * suncol + .7 * res * waterR * (1. - dif) * .75 * suncol;

    lin += 5. * spe * vec3(1.3, 1.0, 0.7) * ks;
    lin = step(0.1, castResult.z) * lin + (1. - step(0.1, castResult.z)) * draw_sky(rd);

    vec3 fogCol = vec3(0.9529, 0.9804, 0.9804);
    float fogRatio = smoothstep(1., 10., dist);
    lin = (1. - fogRatio) * lin + fogRatio * fogCol;
    float skyRatio = smoothstep(.2, 1., abs(rd.y)) * (1. - castResult.z);
    lin = skyRatio * draw_sky(rd) + (1. - skyRatio) * lin;
    return lin;
}

vec2 get_resfrac(in vec2 coord)
{
    vec2 res = coord.xy / iResolution.xy;

    res.y *= iResolution.y / iResolution.x;
    res -= .5;
    res.y += .2;
    res *= 5.;
    return (res);
}

void mainImage(out vec4 cl, in vec2 fc)
{
    vec2 res = get_resfrac(fc);
    float z = .5 * iTime + 2.;
    float cur_x = curve(z);
    vec3 campos = vec3(cur_x, .5, z);
    vec3 view_pos = normalize(vec3(calc_view(z), 0., 1.));
    vec3 diryaw = normalize(view_pos + vec3(0.,-.1,0.));
    vec3 yaw = normalize(cross(diryaw, vec3(0.,1.,0.)));
    vec3 pitch = normalize(cross(yaw, diryaw));
    vec3 direction = normalize(diryaw + res.x * yaw + res.y * pitch);
    vec3 rend = render(campos, direction);

    cl = vec4(rend, 1.);
}

void main(void)
{
    mainImage(gl_FragColor, gl_FragCoord.xy);
}