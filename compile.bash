#!/bin/bash

g++ -g -O3 -L/usr/lib/x86_64-linux-gnu/ -I/usr/include/geotiff MagFromUV.cpp TifGrid.cpp BoundingBox.cpp -o magfromuv  -ltiff -lgeotiff -lz
