#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "linked_list.h"

#define RUN_COUNT 10
#define  N  1000
#define  M  10000
#define  M_MEMBER  0.99
#define  M_INSERT  0.005
#define  M_DELETE  0.005

int thread_count;

struct list_node *head = NULL;
struct list list;

char operation_sequence[M];
int value_sequence[M];

int FillLinkedList(struct list_node *head_p);   //fill linked list with n random unique values

int SetOperationSequence();     //set operation_sequence with randomized 'M', 'I', or 'D'

int SetValueSequence();  //set the value_sequence with m random values

int GetRandomValue(int start, int end); //generate a random value between start and end

int CallOperationSerial();  //call operation based on the array index

int main(int argc, char *argv[]) {
    srand(time(NULL));   // should only be called once

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
    int member_count = M_MEMBER * M;
    int insert_count = M_INSERT * M;
    int delete_count = M_DELETE * M;
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
    for (int i = 0; i < M; i++) {
        int a = GetRandomValue(0, M - 1);
        int b = GetRandomValue(0, M - 1);
        char temp = operation_sequence[a];
        operation_sequence[a] = operation_sequence[b];
        operation_sequence[b] = temp;
    }
    for (int i = 0; i < M; i++) {
        printf("%c\n", operation_sequence[i]);
    }

}

int SetValueSequence() {
    for (int i = 0; i < M; i++) {
        value_sequence[i] = GetRandomValue(0, 65535);
    }
}

int GetRandomValue(int start, int end) {
    int r = rand();
    while (r < start || r > end) {
        r = rand();
    }

    return r;
}

int CallOperationSerial() {
    for (int i = 0; i < M; i++) {
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