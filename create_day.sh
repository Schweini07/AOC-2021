#!/bin/bash
mkdir "Day$1"
mkdir "Day$1/src"
cp "makefile (template)" "Day$1"
mv "Day$1/makefile (template)" "Day$1/makefile"
cp "template.cpp" "Day$1/src"
mv "Day$1/src/template.cpp" "Day$1/src/main.cpp"
touch "Day$1/puzzle_input.txt"