#!/bin/bash

echo "testing case for 3 inputs"
./coolness 1 2 3

echo "testing case for invalid input"
./coolness -10000

echo "testing case for no input"
./coolness

echo "testing for one input"
./coolness 10

echo "testing for two inputs"
./coolness 10 15


