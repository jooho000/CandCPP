Wirtten by: Jooho Lee

UCSC ID: jlee897

3/12/2024

CSE 101

professor Tantalo

PA8

Makefile:

	make: makes Order
	make WordFrequency: makes WordFrequency
	make DictionaryTest: makes DictionaryTest
	make clean: removes binary files
	make OrderCheck: runs Order in valgrind on in4 junk4
	make WordFrequencyCheck: runs WordFrequency in valgrind on in4 junk4
	make DictionaryCheck: runs DictionaryTest in valgrind

Dictionary.cpp:

	Dictionary ADT 

Dictionary.h:

	header for Dictionary.cpp

DictionaryTest.cpp:

    test cases for Dictionary.cpp

Order.cpp:

	reads from given file and outputs to given file an inorder list

WordFrequency.cpp:

	reads from given file and prints out frequncy of each word

