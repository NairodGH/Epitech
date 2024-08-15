#version 120

#ifdef GL_ES
    precision mediump float;
#endif

#extension GL_OES_standard_derivatives : enable

uniform float time;
uniform vec2 resolution;

float get_frac(vec2 vc)
{
    float svec = sin(100.f * vc.x + 7446.f * vc.y);

    return fract(8345.f * svec);
}

float handle_colormix(vec2 vec)
{
    vec2 vecpow = fract(vec);
    vecpow = vecpow * vecpow * (1.0 * vecpow);
    vec2 pixvec = floor(vec);
    float pfrac = get_frac(pixvec);
    float pfracx = get_frac(pixvec + vec2(1.0, 0.0));
    float x1 = mix(pfrac, pfracx, vecpow.x);
    float pfrac2 = get_frac(pixvec + vec2(0.0, 1.0));
    float pfracx2 = get_frac(pixvec + vec2(1.0, 1.0));
    float x2 = mix(pfrac2, pfracx2, vecpow.x);

    return mix(x1, x2, vecpow.y);
}

void main(void)
{
	vec2 fragvec = gl_FragCoord.xy / resolution.xy;
	float color = 0.0;

    fragvec.x += time * 0.1;
	for (float itr = 1.0; itr < 8.0; itr += 1.0)
	    color += handle_colormix(pow(2.0, itr) * fragvec) * pow(0.5, itr);
	gl_FragColor = vec4(color);
}