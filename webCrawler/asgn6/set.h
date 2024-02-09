#ifndef SET_H_
#define SET_H_
#include <stdbool.h>

typedef struct Node {  
    char *key;
    void *item;
    struct Node *next;
    struct Node *previous;
}Node;

typedef struct {
    Node *head;
    Node *firstElement;
    int count;
}set_t;

/* Create a new (empty) set; return NULL if error. */
set_t* set_new(void);

Node *fetchNode(set_t *set);

/* Insert item, identified by a key (string), into the given set.
 * The key string is copied for use by the set.
 * Return false if key exists, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool set_insert(set_t *set, const char *key, void *item);

/* Return the item associated with the given key;
 * return NULL if set is NULL, key is NULL, or key is not found.
 */

/* Delete the whole set; ignore NULL set.
 * Provide a function that will delete each item (may be NULL).
 */
void set_delete(set_t *set);

Node *fetchNode(set_t *set);

#endif // SET_H_
