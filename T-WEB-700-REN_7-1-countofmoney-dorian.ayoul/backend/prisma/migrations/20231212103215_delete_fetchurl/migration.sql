/*
  Warnings:

  - You are about to drop the column `fetchUrl` on the `Crypto` table. All the data in the column will be lost.

*/
-- AlterTable
ALTER TABLE "Crypto" DROP COLUMN "fetchUrl",
ALTER COLUMN "imageUrl" DROP NOT NULL;
