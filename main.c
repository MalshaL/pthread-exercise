#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "linked_list.h"

#define run_count 10
#define  n  1000
#define  m  10000
#define  m_member  0.99
#define  m_insert  0.005
#define  m_delete  0.005

char operation_sequence[m];
int value_sequence[m];

int FillLinkedList(struct list_node *head_p);   //fill linked list with n random unique values

int SetOperationSequence();     //set operation_sequence with randomized 'M', 'I', or 'D'

int SetValueSequence();  //set the value_sequence with m random values

int main(int argc, char *argv[]) {
    struct list_node *head = NULL;
    struct list list;
    list.head = head;

    Insert(5, &list.head);
    Insert(3, &list.head);
    Insert(7, &list.head);
    Insert(1, &list.head);
    Insert(9, &list.head);
    Insert(34, &list.head);
    Delete(1, &list.head);
    printf("%d \n", Member(4, list.head));
    Print(list);

    return 0;
}

int FillLinkedList(struct list_node *head_p){

}

int SetOperationSequence(){

}

int SetValueSequence(){

}