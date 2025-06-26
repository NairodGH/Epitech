#!/bin/sh
set -e

if [ "${1#-}" != "${1}" ] || [ -z "$(command -v "${1}")" ] || { [ -f "${1}" ] && ! [ -x "${1}" ]; }; then
	set -- node "$@"
fi

# update db
pnpx prisma migrate deploy
pnpx prisma generate

# node src/fixtures.ts

pnpm start

exec "$@"
