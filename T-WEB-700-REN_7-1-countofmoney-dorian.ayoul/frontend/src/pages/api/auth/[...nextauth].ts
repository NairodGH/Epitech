import { axiosInstance } from "@/axios/axios";
import { LoginDto } from "@/store/api/backendApi/endpoints/v1";
import { NextApiRequest, NextApiResponse } from "next";
import NextAuth from "next-auth/next";
import CredentialsProvider from "next-auth/providers/credentials";
import Google from "next-auth/providers/google";

async function getProfile(token: string) {
  const { data: profileData } = await axiosInstance.get("/users/profile", {
    headers: {
      Authorization: `Bearer ${token}`,
    },
  });

  return profileData;
}

export default async function auth(req: NextApiRequest, res: NextApiResponse) {
  return await NextAuth(req, res, {
    session: {
      strategy: "jwt",
      maxAge: 30 * 24 * 60 * 60, // 30 days
    },
    pages: {
      signIn: "/login",
    },
    providers: [
      CredentialsProvider({
        name: "credentials",
        credentials: {
          email: { label: "Email", type: "email" },
          password: { label: "Password", type: "password" },
        },

        async authorize(credentials) {
          const payload: LoginDto = {
            email: credentials?.email!,
            password: credentials?.password!,
          };

          const { data: loginData } = await axiosInstance.post(
            "/users/login",
            payload
          );
          if (!loginData.access_token) {
            return null;
          }

          const profileData = await getProfile(loginData.access_token);
          if (!profileData) {
            return null;
          }

          return { ...loginData, ...profileData };
        },
      }),

      Google({
        clientId: process.env.GOOGLE_CLIENT_ID!,
        clientSecret: process.env.GOOGLE_CLIENT_SECRET!,
        authorization: {
          params: {
            prompt: "consent",
            access_type: "offline",
            response_type: "code",
          },
        },
      }),
    ],

    callbacks: {
      async signIn({ account, user }) {
        if (account?.provider === "credentials") return true;
        if (!account) return false;

        const payload = {
          token: account.id_token,
          api: account.provider,
        };
        const { data: oauthData } = await axiosInstance.post(
          "/users/auth/google",
          payload
        );
        if (!oauthData.access_token) {
          return false;
        }

        const profileData = await getProfile(oauthData.access_token);
        if (!profileData) {
          return false;
        }
        (user as any).access_token = oauthData.access_token;
        (user as any).role = profileData.role;
        return true;
      },

      async jwt(props) {
        const { token, account, user } = props;

        if (account) {
          token.role = (user as any).role;
          token.access_token = (user as any).access_token;
        }
        return token;
      },

      async session({ session, token }) {
        (session as any).role = token.role;
        (session as any).access_token = token.access_token;
        return session;
      },
    },

    events: {
      async signOut(message) {
        const token = (message.token as any)?.access_token;

        if (!token) return;

        await axiosInstance.get("/users/logout", {
          headers: {
            Authorization: `Bearer ${token}`,
          },
        });
      },
    },
  });
}
