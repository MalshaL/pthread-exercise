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

int thread_count;

struct list_node *head = NULL;
struct list list;

char operation_sequence[m];
int value_sequence[m];

int FillLinkedList(struct list_node *head_p);   //fill linked list with n random unique values

int SetOperationSequence();     //set operation_sequence with randomized 'M', 'I', or 'D'

int SetValueSequence();  //set the value_sequence with m random values

int GetRandomValue(int start, int end); //generate a random value between start and end

int CallOperationSerial();  //call operation based on the array index

int main(int argc, char *argv[]) {
    thread_count = 8;

//    *head = NULL;
//    struct list list;
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


    SetOperationSequence();


    return 0;
}

int FillLinkedList(struct list_node *head_p) {

}

int SetOperationSequence() {
    int member_count = m_member * m;
    int insert_count = m_insert * m;
    int delete_count = m_delete * m;
    int count = 0;

    while (count < member_count) {
        operation_sequence[count] = 'M';
        count++;
    }

    while (count < insert_count + member_count) {
        operation_sequence[count] = 'I';
        count++;
    }

    while (count < delete_count + insert_count + member_count) {
        operation_sequence[count] = 'D';
        count++;
    }
//    for (int j = 0; j < m; j++) {
//        printf("%c\n", operation_sequence[j]);
//    }

}

int SetValueSequence() {

}

int GetRandomValue(int start, int end) {

}

int CallOperationSerial() {
    for (int i = 0; i < m; i++) {
        int val = value_sequence[i];
        switch (operation_sequence[i]) {
            case 'M':
                Member(val, list.head);
                break;
            case 'I':
                Insert(val, &list.head);
                break;
            case 'D':
                Delete(val, &list.head);
                break;
            default:
                break;
        }
    }
}