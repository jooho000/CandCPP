#ifndef HASH_H_
#define HASH_H_
#include "set.h"
#include <stdbool.h>

typedef struct hashtable_t {
    set_t **myArray;
    int size;
    int currSize;
}hashtable_t;

/* Create a new (empty) hashtable; return NULL if error. */
hashtable_t *hashtable_new(const int num_slots);

/* Insert item, identified by key (string), into the given hashtable.
 * The key string is copied for use by the hashtable.
 * Return false if key exists in ht, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool hashtable_insert(hashtable_t *ht, const char *key, void *item);

/* Delete the whole hashtable; ignore NULL ht.
 * Provide a function that will delete each item (may be NULL).
 */
void hashtable_delete(hashtable_t *ht);


#endif //HASH_H_
