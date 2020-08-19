#!/bin/bash

./nettoyer.sh

cd ../../lib_dir
make

sleep 1

cd ../projet/couleur
make install
