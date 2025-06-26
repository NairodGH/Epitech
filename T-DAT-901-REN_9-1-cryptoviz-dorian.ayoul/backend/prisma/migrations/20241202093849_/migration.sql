-- CreateTable
CREATE TABLE "CryptoDay" (
    "id" TEXT NOT NULL,
    "openingPrice" DOUBLE PRECISION NOT NULL,
    "closingPrice" DOUBLE PRECISION NOT NULL,
    "highPrice" DOUBLE PRECISION NOT NULL,
    "lowPrice" DOUBLE PRECISION NOT NULL,
    "date" TIMESTAMP(3) NOT NULL,
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "cryptoId" TEXT NOT NULL,

    CONSTRAINT "CryptoDay_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "CryptoDay" ADD CONSTRAINT "CryptoDay_cryptoId_fkey" FOREIGN KEY ("cryptoId") REFERENCES "Crypto"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
