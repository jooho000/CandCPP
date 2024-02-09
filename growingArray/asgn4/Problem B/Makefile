CC=gcc
SOURCE=test_growing_arrays.c growing_arrays.c
OBJ=test_growing_arrays.c growing_arrays.o
HEADER=growing_arrays.h

password_checker: ${OBJ} ${HEADER}
	$(CC) $(OBJ) -Wall -Wextra -Wpedantic -o growing_arrays

%.o: %.c $(HEADER)
	$(CC) $< -c

clean:
	rm -rf growing_arrays
	rm -rf *.o
