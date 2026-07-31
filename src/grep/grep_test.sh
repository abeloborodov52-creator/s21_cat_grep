#!/bin/bash

SUCCESS=0
FAIL=0

TEST_FILE="test.txt"

FLAGS=(
    ""
    "-i"
    "-v"
    "-c"
    "-l"
    "-n"
    "-iv"
    "-in"
    "-vn"
    "-cv"
)

PATTERNS=(
    "hello"
    "Hello"
    "grep"
    "123"
    "test"
    "WORLD"
)

for flag in "${FLAGS[@]}"
do
    for pattern in "${PATTERNS[@]}"
    do
        ./s21_grep $flag "$pattern" $TEST_FILE > s21.txt
        grep $flag "$pattern" $TEST_FILE > grep.txt

        diff -s s21.txt grep.txt > /dev/null

        if [ $? -eq 0 ]
        then
            echo "SUCCESS: grep $flag \"$pattern\""
            (( SUCCESS++ ))
        else
            echo "FAIL: grep $flag \"$pattern\""
            (( FAIL++ ))
        fi

        rm -f s21.txt grep.txt
    done
done

echo "SUCCESS: $SUCCESS"
echo "FAIL: $FAIL"