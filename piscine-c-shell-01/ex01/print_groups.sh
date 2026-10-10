#!/bin/sh
# print the user's groups
id -Gn "$FT_USER" | tr ' ' ',' | tr -d '\n'
