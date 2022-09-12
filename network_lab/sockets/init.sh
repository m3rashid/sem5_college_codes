# !/usr/bin/bash

rm -rf ./server && g++ ./server.cpp -o server
rm -rf ./client && g++ ./client.cpp -o client

./server