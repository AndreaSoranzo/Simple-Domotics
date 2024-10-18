#!/bin/bash

qmake -project -nopwd app/
qmake General.pro CONFIG+=release
make