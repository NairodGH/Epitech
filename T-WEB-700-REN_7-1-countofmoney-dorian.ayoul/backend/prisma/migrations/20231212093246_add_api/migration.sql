/*
  Warnings:

  - A unique constraint covering the columns `[coinmarketId]` on the table `Crypto` will be added. If there are existing duplicate values, this will fail.
  - Added the required column `coinmarketId` to the `Crypto` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "Crypto" ADD COLUMN     "coinmarketId" INTEGER NOT NULL;

-- CreateIndex
CREATE UNIQUE INDEX "Crypto_coinmarketId_key" ON "Crypto"("coinmarketId");
