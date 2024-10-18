#!/bin/bash

qmake -project -nopwd app/
qmake General.pro CONFIG+=debug
make