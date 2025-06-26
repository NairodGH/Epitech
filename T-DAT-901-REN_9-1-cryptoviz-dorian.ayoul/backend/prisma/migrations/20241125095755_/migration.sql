/*
  Warnings:

  - A unique constraint covering the columns `[link]` on the table `RSSFeed` will be added. If there are existing duplicate values, this will fail.

*/
-- CreateIndex
CREATE UNIQUE INDEX "RSSFeed_link_key" ON "RSSFeed"("link");
