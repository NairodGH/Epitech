#!/bin/sh
set -e

if [ "${1#-}" != "${1}" ] || [ -z "$(command -v "${1}")" ] || { [ -f "${1}" ] && ! [ -x "${1}" ]; }; then
	set -- node "$@"
fi

pnpm install --prefer-offline

pnpm run build
pnpm run start
