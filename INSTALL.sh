#!/bin/bash
if [[ -n "$SUDO_USER" ]]; then
    echo "Starting installation..."
    gcc echo.c -o echox
    mv echox /usr/bin
    echo "added to /usr/bin"
else
    echo "Please Execute With Sudo [sudo ./INSTALL.sh]"
    exit 1
fi