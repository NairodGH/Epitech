#!/bin/bash

mkdir -p build
rm -f build/*.tar.gz

tar --exclude='.git' \
    --exclude='node_modules' \
    --exclude='storage' \
    --exclude='vendor' \
    --exclude='.env' \
    --exclude='pipeline' \
    --exclude='build' \
    -czf build/back.tar.gz *
