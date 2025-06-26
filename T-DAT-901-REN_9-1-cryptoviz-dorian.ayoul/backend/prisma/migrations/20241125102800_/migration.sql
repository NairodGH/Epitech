/*
  Warnings:

  - Added the required column `pubDate` to the `RSSFeedItem` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "RSSFeedItem" ADD COLUMN     "pubDate" TIMESTAMP(3) NOT NULL;
