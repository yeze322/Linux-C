#!/bin/bash
g++ -g ./thread_pool_version.cpp -lpthread -o run -I ./include/
./run
