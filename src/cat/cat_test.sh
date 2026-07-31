#!/bin/bash

SUCCESS=0
FAIL=0

run_test() {
    FLAGS="$1"
    FILE="$2"

    cat $FLAGS "$FILE" > original.txt
    ./s21_cat $FLAGS "$FILE" > mine.txt

    diff -q original.txt mine.txt > /dev/null

    if [ $? -eq 0 ]
    then
        echo "SUCCESS: $FLAGS $FILE"
        SUCCESS=$((SUCCESS + 1))
    else
        echo "FAIL: $FLAGS $FILE"
        FAIL=$((FAIL + 1))
    fi
}

run_test "" test.txt
run_test "-n" test.txt
run_test "-b" test.txt
run_test "-s" test.txt
run_test "-e" test.txt
run_test "-t" test.txt
run_test "-n -s" test.txt
run_test "-b -s" test.txt
run_test "-e -t" test.txt
run_test "-b -s -e -t" test.txt
rm -f original.txt mine.txt
echo
echo "SUCCESS: $SUCCESS"
echo "FAIL: $FAIL"