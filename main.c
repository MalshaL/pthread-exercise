#include <stdio.h>
#include "linked_list.h"

struct list list;

int main() {
    struct list_node *head = NULL;
    list.head = head;
    Insert( 5, &list.head );
    Insert( 3, &list.head );
    Insert( 7, &list.head );
    Insert( 1, &list.head );
    Insert( 9, &list.head );
    Insert( 34, &list.head );
    Delete( 1, &list.head );
    printf("%d \n",Member( 4, list.head ) );
    Print( list );
    return 0;
}