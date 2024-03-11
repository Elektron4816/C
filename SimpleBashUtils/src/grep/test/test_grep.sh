#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
TEST_FILE_1="./test/a.txt ./test/b.txt"
TEST_FILE_2="./test/a.txt"
LOGER="./test/grep_log.txt"

FLAGS="-i -v -c -l -n -h -s -iv -ic -il -in -ih -is -vc -vl -vn -vh -vs -cl -cn -ch -cs -ln -lh -ls -nh -ns -hs -ivc -ivl -ivn -ivh -ivs -vcl -vcn -vch -vcs -cln -clh -cls -lnh -lns -ivclnhs -o -oi -ov -ocl -ol -on -oh -os -oc" 

for var in $FLAGS
do
    TEST="$TEST_FILE_1"
    ./s21_grep $var hello $TEST > ./test/21_grep.txt
    grep $var hello $TEST > ./test/grep.txt
    if cmp -s ./test/21_grep.txt ./test/grep.txt; then
        ((SUCCESS++))
    else
        echo "TEST_FILE_1"$var >> $LOGER
        ((FAIL++))
    fi
     rm ./test/21_grep.txt ./test/grep.txt
done


for var in $FLAGS
do
    TEST="$TEST_FILE_2"
    ./s21_grep $var hello $TEST > ./test/21_grep.txt
    grep $var hello $TEST > ./test/grep.txt
    if cmp -s ./test/21_grep.txt ./test/grep.txt; then
        ((SUCCESS++))
    else
        echo "TEST_FILE_2"$var >> $LOGER
        ((FAIL++))
    fi
     rm ./test/21_grep.txt ./test/grep.txt
done

echo SUCCESS: $SUCCESS
echo FAIL: $FAIL