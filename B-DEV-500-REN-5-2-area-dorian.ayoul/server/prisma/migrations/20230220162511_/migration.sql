-- AlterEnum
-- This migration adds more than one value to an enum.
-- With PostgreSQL versions 11 and earlier, this is not possible
-- in a single migration. This can be worked around by creating
-- multiple migrations, each migration adding only one value to
-- the enum.


ALTER TYPE "ActionType" ADD VALUE 'DETECT_STREAMERS_PLAY_GAMES_TWITCH';
ALTER TYPE "ActionType" ADD VALUE 'DETECT_USER_STREAM_GAMES_TWITCH';
