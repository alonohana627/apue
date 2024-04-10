#!/bin/sh
find . \( -name "*.c" -o -name "*.h" \) -not -path "./examples/*" > cppcheck_files.txt
cppcheck --enable=all --force --std=c99 --language=c --error-exitcode=1 --inconclusive --quiet --suppress=missingIncludeSystem --suppress=missingInclude --file-list=cppcheck_files.txt 2> cppcheck_results.txt
