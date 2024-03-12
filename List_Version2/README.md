Wirtten by: Jooho Lee

UCSC ID: jlee897

2/13/2024

CSE 101

professor Tantalo

PA5

Makefile:

	make: makes Shuffle
	make ListTest: make ListTest
	make clean: removes binary files
	make check1: runs valgrind on ListTest
	make check2: runs valgrind on Shuffle with CLA 35

List.cpp:

	List ADT 

List.h:

	header for List.cpp

ListTest.cpp:

    test cases for List.cpp
	for use: run "make ListTest" then "./ListTest <outFile>

Shuffle.cpp:

	main function for assignment
