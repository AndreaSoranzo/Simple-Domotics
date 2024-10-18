#!/bin/bash

if [ "$1" = "-v" ]
    then
        valgrind --leak-check=full --show-leak-kinds=all ./build/debug/App
    else
       ./build/debug/App
fi