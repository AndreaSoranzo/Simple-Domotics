#!/bin/bash
cd test
rm qrc_resources.cpp  qrc_resources.o
qmake -project QT+=widgets QT+=charts
qmake
make
if [ "$1" = "-v" ]
    then
        valgrind --leak-check=full --show-leak-kinds=all ./test
    else
        ./test;
fi