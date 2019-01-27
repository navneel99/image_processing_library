#!/bin/bash
sudo apt update
sudo apt search openblas
sudo apt install libopenblas-dev
sudo update-alternatives --config libblas.so.3


