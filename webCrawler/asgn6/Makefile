CC=gcc
SOURCE=crawler.c curl.c pagedir.c url.c set.c hashtable.c 
HEADER=crawler.h curl.h pagedir.h url.h set.h hashtable.h

craler_check: ${HEADER}
	$(CC) $(SOURCE) -lcurl -g -O0 -o crawler
 
%.o: %.c $(HEADER)
	$(CC) $< -c

clean:
	rm -rf crawler
	rm -rf *.o
