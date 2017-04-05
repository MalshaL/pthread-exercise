//
// Created by Malsha on 4/5/2017.
//

#include <stddef.h>
#include <malloc.h>

#ifndef LAB2_LINKED_LIST_H
#define LAB2_LINKED_LIST_H

#endif //LAB2_LINKED_LIST_H

struct list_node {
    int data;
    struct list_node* next;
};

struct list {
    struct list_node* head;
};

int Member ( int value, struct list_node* head_p) {
    struct list_node* curr_p = head_p;

    while ( curr_p != NULL && curr_p->data < value)
        curr_p = curr_p->next;

    if ( curr_p == NULL || curr_p->data > value ) {
        return 0;
    } else {
        return 1;
    }
}

int Insert ( int value, struct list_node** head_p ) {
    struct list_node* curr_p = *head_p;
    struct list_node* pred_p = NULL;
    struct list_node* temp_p;

    while ( curr_p != NULL && curr_p->data < value ) {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if ( curr_p == NULL || curr_p->data > value ){
        temp_p = malloc(sizeof(struct list_node));
        temp_p->data = value;
        temp_p->next = curr_p;
        if ( pred_p == NULL )
            //new first node
            *head_p = temp_p;
        else
            pred_p->next = temp_p;
        return 1;
    }
    else {
        //value is already in list
        return 0;
    }
}

int Delete ( int value, struct list_node** head_p) {
    struct list_node* curr_p = *head_p;
    struct list_node* pred_p = NULL;

    while ( curr_p != NULL && curr_p->data < value ) {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if ( curr_p != NULL && curr_p->data == value ) {
        if ( pred_p == NULL ) {
            //deleting first node
            *head_p = curr_p->next;
            free( curr_p );
        } else {
            pred_p->next = curr_p->next;
            free( curr_p );
        }
        return 1;
    } else {
        //value is not in list
        return 0;
    }
}

void Print (struct list list ) {
    if ( list.head != NULL ) {
        printf( "%d, ", list.head->data  );
        struct list_node* curr_p = list.head->next;
        while ( curr_p != NULL ) {
            printf( "%d, ", curr_p->data );
            curr_p = curr_p->next;
        }
    }
}