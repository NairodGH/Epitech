-- CreateTable
CREATE TABLE "RSSFeed" (
    "id" TEXT NOT NULL,
    "link" TEXT NOT NULL,
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "updatedAt" TIMESTAMP(3) NOT NULL,

    CONSTRAINT "RSSFeed_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "RSSFeedItem" (
    "id" TEXT NOT NULL,
    "title" TEXT NOT NULL,
    "content" TEXT NOT NULL,
    "imageUrl" TEXT,
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "feedId" TEXT NOT NULL,

    CONSTRAINT "RSSFeedItem_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "RSSFeedItem" ADD CONSTRAINT "RSSFeedItem_feedId_fkey" FOREIGN KEY ("feedId") REFERENCES "RSSFeed"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
