#!/bin/sh

# Display the IDs of the last 5 commits
git log -n 5 --format="%H"

