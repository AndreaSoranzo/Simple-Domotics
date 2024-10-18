#!/bin/bash

cd test/
make clean
rm test
cd ..
make clean
rm build/debug/*
rm build/release/*