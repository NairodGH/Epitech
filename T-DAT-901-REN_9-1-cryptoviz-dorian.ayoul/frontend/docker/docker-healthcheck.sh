#!/bin/sh
set -e

if curl --fail http://localhost:3000; then
	exit 0
fi

exit 1
