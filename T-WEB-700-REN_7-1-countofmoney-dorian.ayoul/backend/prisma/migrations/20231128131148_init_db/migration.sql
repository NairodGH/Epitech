-- CreateEnum
CREATE TYPE "Roles" AS ENUM ('USER', 'ADMIN');

-- CreateEnum
CREATE TYPE "Period" AS ENUM ('MINUTE', 'HOUR', 'DAY');

-- CreateEnum
CREATE TYPE "ConstantType" AS ENUM ('NB_CRYPTO', 'NB_ARTICLE');

-- CreateTable
CREATE TABLE "User" (
    "id" TEXT NOT NULL,
    "email" TEXT NOT NULL,
    "password" TEXT NOT NULL,
    "token" TEXT NOT NULL,
    "role" "Roles" NOT NULL DEFAULT 'USER',
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "updatedAt" TIMESTAMP(3) NOT NULL,

    CONSTRAINT "User_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Crypto" (
    "id" TEXT NOT NULL,
    "name" TEXT NOT NULL,
    "imageUrl" TEXT NOT NULL,
    "fetchUrl" TEXT NOT NULL,

    CONSTRAINT "Crypto_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "CryptoValue" (
    "id" TEXT NOT NULL,
    "unitDollarPrice" DOUBLE PRECISION NOT NULL,
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "cryptoId" TEXT NOT NULL,
    "period" "Period" NOT NULL,

    CONSTRAINT "CryptoValue_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "RSSFeed" (
    "id" TEXT NOT NULL,
    "name" TEXT NOT NULL,
    "link" TEXT NOT NULL,
    "description" TEXT NOT NULL,
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "updatedAt" TIMESTAMP(3) NOT NULL,

    CONSTRAINT "RSSFeed_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "RSSFeedItem" (
    "id" TEXT NOT NULL,
    "title" TEXT NOT NULL,
    "content" TEXT NOT NULL,
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "feedId" TEXT NOT NULL,

    CONSTRAINT "RSSFeedItem_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Constant" (
    "id" TEXT NOT NULL,
    "name" "ConstantType" NOT NULL,
    "value" INTEGER NOT NULL,

    CONSTRAINT "Constant_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "_CryptoToUser" (
    "A" TEXT NOT NULL,
    "B" TEXT NOT NULL
);

-- CreateIndex
CREATE UNIQUE INDEX "User_email_key" ON "User"("email");

-- CreateIndex
CREATE UNIQUE INDEX "_CryptoToUser_AB_unique" ON "_CryptoToUser"("A", "B");

-- CreateIndex
CREATE INDEX "_CryptoToUser_B_index" ON "_CryptoToUser"("B");

-- AddForeignKey
ALTER TABLE "CryptoValue" ADD CONSTRAINT "CryptoValue_cryptoId_fkey" FOREIGN KEY ("cryptoId") REFERENCES "Crypto"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "RSSFeedItem" ADD CONSTRAINT "RSSFeedItem_feedId_fkey" FOREIGN KEY ("feedId") REFERENCES "RSSFeed"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "_CryptoToUser" ADD CONSTRAINT "_CryptoToUser_A_fkey" FOREIGN KEY ("A") REFERENCES "Crypto"("id") ON DELETE CASCADE ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "_CryptoToUser" ADD CONSTRAINT "_CryptoToUser_B_fkey" FOREIGN KEY ("B") REFERENCES "User"("id") ON DELETE CASCADE ON UPDATE CASCADE;
