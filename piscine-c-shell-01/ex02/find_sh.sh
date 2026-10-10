#!/bin/sh
# find all files ending in .sh
find . -type f -name "*.sh" -exec basename {} .sh \;
