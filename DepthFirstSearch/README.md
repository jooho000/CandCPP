Wirtten by: Jooho Lee

UCSC ID: jlee897

1/30/2024

CSE 101

professor Tantalo

PA3

Makefile:

	make clean: removes .o .exe files

	make GraphTest: makes GraphTest, run by using ./GraphTest and will run test cases for Graph.c

	make FindPath: will make FindPath, run by using ./FindPath <input file> <output file>

	make checkFind: valgrind for FindPath.c

	make checkTest: valgrind for GraphTest.c

List.c:

	functions for FindPath.c, Graph.c GraphTest.c to use

List.h:

	header for List.c

Graph.c:

	functions for FindPath.c and GraphTest.c to use

Graph.h:

	header for Graph.c

GraphTest.c:

	test cases for Graph.c

FindComponents.c:

	gets input numbers from a file and constructs a graph and runs DFS() and outputs adjacency list and SCCs


