#!/bin/bash
if [[ -n "$SUDO_USER" ]]; then
    echo "Starting installation..."
    cd echo-clone
    gcc echo.c -o echox
    mv echox /usr/bin
    echo "added to /usr/bin"
    cd ..
    rm -rf echo-clone -y
    echo "Cleaned up ..."
else
    echo "Not executed via sudo"
    exit 1
fi