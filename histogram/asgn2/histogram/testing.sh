#!/bin/bash

echo "testing with no resizing"
echo 1 2 3 4 5 | ./histogram 

echo "testing with resizing"
echo 20 30 40 50 | ./histogram 

echo "testing with more resizing"
echo  30 50 70 80 100 200 145 132 156 | ./histogram 
