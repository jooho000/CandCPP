Wirtten by: Jooho Lee

UCSC ID: jlee897

2/20/2024

CSE 101

professor Tantalo

PA6

Makefile:

	make: makes Arithmetic
	make BigIntegerTest: makes BigINtegerTest
	make ListClient: makes ListClient
	make clean: removes binary files
	make ArithmeticCheck: runs Arithmetic in valgrind on in4 junk4
	make BigIntegerCheck: runs BigIntegerTest in valgrind
	make ListCheck: runs ListTest in valgrind

List.cpp:

	List ADT 

List.h:

	header for List.cpp

ListTest.cpp:

    test cases for List.cpp
	for use: run "make ListTest" then "./ListTest <outFile>

Arithmetic.cpp:

	main function for assignment

BigInteger.cpp:

	BigInteger ADT

BigInteger.h

	header file for BigInteger.cpp

BigIntegerTest.cpp:

	test cases for BigInteger.cpp
