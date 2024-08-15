/** @type {import('next').NextConfig} */
const withTM = require("next-transpile-modules")(["echarts", "zrender"]);

const nextConfig = {
  reactStrictMode: true,

  images: {
    domains: ["lh3.googleusercontent.com"],
  },

  async redirects() {
    return [
      {
        source: "/",
        destination: "/dashboard",
        permanent: true,
      },
    ];
  },
};

module.exports = withTM(nextConfig);
