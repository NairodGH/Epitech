#!/bin/sh
set -e

if curl --fail http://localhost:4000/api; then
	exit 0
fi

exit 1
