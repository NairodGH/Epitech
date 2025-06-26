-- CreateEnum
CREATE TYPE "Period" AS ENUM ('MINUTE', 'HOUR', 'DAY');

-- CreateTable
CREATE TABLE "Crypto" (
    "id" TEXT NOT NULL,
    "coinmarketId" INTEGER NOT NULL,
    "name" TEXT NOT NULL,
    "imageUrl" TEXT,

    CONSTRAINT "Crypto_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "CryptoValue" (
    "id" TEXT NOT NULL,
    "unitDollarPrice" DOUBLE PRECISION NOT NULL,
    "period" "Period" NOT NULL,
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "cryptoId" TEXT NOT NULL,

    CONSTRAINT "CryptoValue_pkey" PRIMARY KEY ("id")
);

-- CreateIndex
CREATE UNIQUE INDEX "Crypto_coinmarketId_key" ON "Crypto"("coinmarketId");

-- AddForeignKey
ALTER TABLE "CryptoValue" ADD CONSTRAINT "CryptoValue_cryptoId_fkey" FOREIGN KEY ("cryptoId") REFERENCES "Crypto"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
