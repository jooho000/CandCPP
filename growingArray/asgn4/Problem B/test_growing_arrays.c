#include "growing_arrays.h" 
// Testing code. You can modify this and check your own test cases.
struct Table table;

int main() {
    table.nval = 0;
    table.max = INIT_SIZE;
    table.record = malloc(sizeof(Record) * table.max);

    // test add_record
    Record r1 = {"Alice", 1};
    Record r2 = {"Bob", 2};
    Record r3 = {"Char", 3};
    Record r4 = {"Ali", 1};
    Record r5 = {"Bob", 5};
    Record r6 = {"Chae", 3};
    int i1 = add_record(r1);
    int i2 = add_record(r2);
    int i3 = add_record(r3);
    int i4 = add_record(r4);
    int i5 = add_record(r5);
    int i6 = add_record(r6);
    printf("added records at indices %d, %d, %d, %d, %d, %d\n", i1, i2, i3, i4, i5, i6);

    // test get_id and get_record
    int id = get_id("Bob");
    Record r = get_record(i1);
    printf("record at index %d: name=%s, id=%d\n", i1, r.name, r.id);
    printf("record with name 'Bob': id=%d\n", id);

    int id2 = get_id("Charlie");
    Record rsec = get_record(i3);
    printf("record at index %d: name=%s, id=%d\n", i3, rsec.name, rsec.id);
    printf("record with name 'Charlie': id=%d\n", id2);

    for (int count = 0; count < table.nval; count++) {
        printf("name: %s, id: %d\n", table.record[count].name, table.record[count].id);
    }
    printf("nval: %d\n",table.nval);

    // test del_record
    int success = del_record("Bob");
    printf("deleted record with name 'Bob': %d\n", success);
    id = get_id("Bob");
    printf("record with name 'Bob': id=%d\n", id);

    for (int count = 0; count < table.nval; count++) {
        printf("name: %s, id: %d\n", table.record[count].name, table.record[count].id);
    }
    printf("nval: %d\n",table.nval);

    int success2 = del_record("Chae");
    printf("deleted record with name 'Chae': %d\n", success2);
    int idChae = get_id("Chae");
    printf("record with name 'Chae': id=%d\n", idChae);

    for (int count = 0; count < table.nval; count++) {
        printf("name: %s, id: %d\n", table.record[count].name, table.record[count].id);
    }
    printf("nval: %d\n",table.nval);

    Record r7 = {"test", 7};
    int i7 = add_record(r7);
    printf("added records at index %d\n",i7);

    for (int count = 0; count < table.nval; count++) {
        printf("name: %s, id: %d\n", table.record[count].name, table.record[count].id);
    }
    printf("nval: %d\n",table.nval);

    free(table.record);
    return 0;
}

/*
Output for the above testing code:

added records at indices 0, 1, 2
record at index 0: name=Alice, id=1
record with name 'Bob': id=2
deleted record with name 'Bob': 1
record with name 'Bob': id=0


*/
