#!/bin/bash
find ./ -maxdepth 1 -type f -name "*.md" -print0 | sed "s/.md//g" | xargs -0 -I {} sh do.sh {}
