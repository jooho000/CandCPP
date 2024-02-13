Wirtten by: Jooho Lee

UCSC ID: jlee897

2/8/2024

CSE 101

professor Tantalo

PA4

Makefile:

    make: creates executable ./Sparse

	make clean: removes .o .exe files

	make MatrixTest: makes executable file of test cases for Matrix.c

	make ListTest: makes executable file of test cases for List.c

	make SparseCheck: runs valgrind for ./Sparce <inFile> <outFile>

	make MatrixCheck: runs valgrind for ./MatrixTest <outFile>

	make ListCheck: runs valgrind for ./ListTest

List.c:

	functions for FindPath.c, Graph.c GraphTest.c to use

List.h:

	header for List.c

ListTest.c:

    test cases for List.c
	for use: run "make ListTest" then "./ListTest <outFile>

Matrix.c:

	functions for Sparse.c and MatrixTest.c to use

Matrix.h:

	header for Matrix.c

MatrixTest.c:

	test cases for Matrix.c
	for use: run "make MatrixTest" then "./MatrixTest <outFile>"

Sparse.c:

	gets input numbers from a file and constructs 2 Matrices of size nxn and prints out resulting matrices


