#!/bin/bash

if [ "$1" = "-v" ]
    then
        valgrind --leak-check=full --show-leak-kinds=all ./build/release/App
    else
        ./build/release/App
fi