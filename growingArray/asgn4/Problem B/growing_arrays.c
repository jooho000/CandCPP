#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "growing_arrays.h"

// returns the index of the item added  
int add_record(Record record) {

    if (table.nval == 0) {
        table.record[0] = record;
        table.nval++;
        return 0;
    }
	
    if (table.nval == table.max) {
        table.max = table.max * GROW_SIZE;
        table.record = realloc(table.record, table.max * sizeof(Record));
        table.record[table.nval] = record;
        table.nval++;
        return table.nval-1;
    }

    table.record[table.nval] = record;
    ++table.nval;
    return table.nval-1;
}

// return 0 if there is no matching record
// return 1 if there is a matching record and deletes it and 
// moves records
int del_record(const char *name) {

    int myIndex,myStatus=0;
	for (int i = 0; i < table.nval ; i++) {
        if (strcmp(table.record[i].name,name) == 0) {
            myIndex = i;
            myStatus = 1;
            break;
        }
    }

    if (myStatus == 1) {

        for (int j = myIndex; j < table.nval - 1; j++) {
            memmove(&table.record[j],&table.record[j+1],sizeof(Record));
        }
        table.nval--;
        return 1;
    }

    return 0;
}  

// returns id of student record of the first matching record
int get_id(const char *name) {

	for (int i = 0; i < table.nval ; i++) {
        if (strcmp(table.record[i].name,name) == 0) {
            return table.record[i].id;
        }
    }

    return 0;
}

// returns record with a valid index, 0 to max-1 
Record get_record(int index) {
	return table.record[index];
}