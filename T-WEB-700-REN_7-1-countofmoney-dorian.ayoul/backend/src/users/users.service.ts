import { Injectable, Inject, HttpException, HttpStatus } from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import { PrismaClient, User } from '@prisma/client';
import { LoginDto } from './dto/login.dto';
import * as bcrypt from 'bcrypt';
import { UserDto } from './dto/user.dto';
import { OAuthDto } from './dto/oauth.dto';
import { OAuth2Client, TokenPayload } from 'google-auth-library';
import { UpdateUserDto } from './dto/updateuser.dto';

@Injectable()
export class UsersService {
  constructor(
    @Inject('Prisma') private readonly prisma: PrismaClient,
    private readonly jwtService: JwtService,
  ) {}

  async validateUser(email: string, password: string): Promise<User> {
    const user = this.prisma.user
      .findUnique({
        where: {
          email: email,
        },
      })
      .then((user) => {
        if (user) {
          if (bcrypt.compareSync(password, user.password)) {
            return user;
          }
        }
        return null;
      });
    return user;
  }

  async login(user: LoginDto) {
    const DBuser = await this.validateUser(user.email, user.password);
    if (!DBuser) {
      throw new HttpException('Could not log in', HttpStatus.FORBIDDEN);
    }
    return {
      access_token: this.jwtService.sign({
        id: DBuser.id,
        email: DBuser.email,
        role: DBuser.role,
      }),
    };
  }

  async registerNewUser(
    user: Parameters<typeof this.prisma.user.create>[0]['data'],
  ) {
    const defaultCryptos = await this.prisma.crypto
      .findMany({
        where: {
          default: true,
        },
      })
      .then((cryptos) => cryptos.map((crypto) => ({ id: crypto.id })));

    const hashedPassword = bcrypt.hashSync(user.password, 10);
    const newUser = await this.prisma.user.create({
      data: {
        email: user.email,
        password: hashedPassword,
        token: user.token,
        cryptos: {
          connect: defaultCryptos,
        },
      },
    });

    return {
      id: newUser.id,
      email: newUser.email,
      role: newUser.role,
      cryptos: defaultCryptos.map((crypto) => crypto.id),
    };
  }

  async register(user: LoginDto) {
    const regex = /^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$/i;
    if (!regex.test(user.email)) {
      throw new HttpException('Incorrect email format', HttpStatus.FORBIDDEN);
    }
    if (await this.prisma.user.findUnique({ where: { email: user.email } })) {
      throw new HttpException('User already exists', HttpStatus.FORBIDDEN);
    }
    if (user.password.length < 8) {
      throw new HttpException(
        'Incorrect password format',
        HttpStatus.FORBIDDEN,
      );
    }

    return (await this.registerNewUser({ ...user, token: '' })) as UserDto;
  }

  async authGoogle(user: OAuthDto) {
    const client = new OAuth2Client();

    async function verify() {
      const ticket = await client.verifyIdToken({
        idToken: user.token,
        audience: process.env.GOOGLE_CLIENT_ID,
      });
      const payload = ticket.getPayload();
      return payload;
    }
    let payload: TokenPayload;
    try {
      payload = await verify();
    } catch (error) {
      throw new HttpException('Could not verify', HttpStatus.FORBIDDEN);
    }

    const dbUser = await this.prisma.user.findUnique({
      where: {
        email: payload.email,
      },
    });

    if (dbUser) {
      return {
        access_token: this.jwtService.sign({
          id: dbUser.id,
          email: dbUser.email,
          role: dbUser.role,
        }),
      };
    }

    const newUser = await this.registerNewUser({
      email: payload.email,
      password: '',
      token: user.token,
    });

    return {
      access_token: this.jwtService.sign({
        id: newUser.id,
        email: newUser.email,
        role: newUser.role,
      }),
    };
  }

  async logout(req) {
    req.headers.authorization = null;
  }

  async profile(req: any): Promise<UserDto> {
    const user = await this.prisma.user.findUnique({
      where: {
        id: req.user.id,
      },
      select: {
        email: true,
        role: true,
        cryptos: {
          select: {
            id: true,
          },
        },
      },
    });
    return {
      ...user,
      cryptos: user.cryptos.map((crypto) => crypto.id),
    };
  }

  async updateProfile(user: UpdateUserDto, req): Promise<UpdateUserDto> {
    const jwt = req.headers.authorization.split(' ')[1];
    const decoded = this.jwtService.decode(jwt);
    const email = decoded['email'];

    const updatedUser = await this.prisma.user.update({
      where: {
        email: email,
      },
      data: {
        cryptos: {
          connect: user.cryptos.map((crypto) => ({ id: crypto })),
        },
        keywords: {
          set: user.keywords,
        },
      },
      select: {
        cryptos: {
          select: {
            id: true,
          },
        },
        keywords: true,
      },
    });
    return {
      ...updatedUser,
      cryptos: updatedUser.cryptos.map((crypto) => crypto.id),
      keywords: updatedUser.keywords,
    };
  }
}
