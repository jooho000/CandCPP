#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {

    node *slowPointer = head, *fastPointer = head;

    if (head == NULL) {
        return 0;
    }

    while (fastPointer != NULL && fastPointer->next != NULL) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;

        if (slowPointer == fastPointer) {
            return 1;
        }
    }

    return 0;
}
