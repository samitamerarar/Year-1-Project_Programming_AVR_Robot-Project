#!/bin/bash

clear

cd lib_dir
make

cd ../exec_dir
make install
