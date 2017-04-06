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
int chunk_length;

int FillLinkedList();   //fill linked list with n random unique values

int SetOperationSequence();     //set operation_sequence with randomized 'M', 'I', or 'D'

int SetValueSequence();  //set the value_sequence with m random values

int GetRandomValue(int start, int end); //generate a random value between start and end

int RunSerialOperations();  //call operation
int RunMutexOperations(); //create join and free the threads
int RunRWLockOperations(); //create join and free the threads
void *CallOperationMutex(void *arrayStartId);  //call operation
void *CallOperationRWLocks(void *arrayStartId);  //call operation

int main(int argc, char *argv[]) {
    srand(time(NULL));   // should only be called once
    thread_count = 8;
    chunk_length = M / thread_count;

    SetValueSequence();
    SetOperationSequence();

    RunSerialOperations();

//    list.head = head;
//
//    Insert(5, &list.head);
//    Insert(3, &list.head);
//    Insert(7, &list.head);
//    Insert(1, &list.head);
//    Insert(9, &list.head);
//    Insert(34, &list.head);
//    Delete(1, &list.head);
//    printf("%d \n", Member(4, list.head));
//    Print(list);

    return 0;
}

int FillLinkedList() {

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
//    for (int i = 0; i < M; i++) {
//        printf("%c\n", operation_sequence[i]);
//    }

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

int RunSerialOperations() {
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

int RunMutexOperations() {
    for (int thread_id = 0; thread_id < thread_count; thread_id++) {
        //TODO initiate a thread Eg: thread_0,  pthreadcreat(... CallOperationMutex.. id)
        //id =thread_id * chunk_length
    }
}

int RunRWLockOperations() {
    for (int thread_id = 0; thread_id < thread_count; thread_id++) {
        //TODO initiate a thread Eg: thread_0,  pthreadcreat(... CallOperationRWLocks.. id)
        //id =thread_id * chunk_length
    }
}

void *CallOperationMutex(void *arrayStartId) {
    int my_id = (int) arrayStartId;

    for (int i = my_id; i < my_id + chunk_length; i++) {
        int val = value_sequence[i];
        //TODO add mutexes
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

void *CallOperationRWLocks(void *arrayStartId) {
    int my_id = (int) arrayStartId;

    for (int i = my_id; i < my_id + chunk_length; i++) {
        int val = value_sequence[i];
        //TODO add rwlocks
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
