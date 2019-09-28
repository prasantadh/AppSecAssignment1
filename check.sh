#! /bin/bash

while (inotifywait -e modify *.c); do
    clear;
    echo "Test Results:";
    make test && ./test;
    echo; echo "Main Execution:";
    make main && ./main;
done;
