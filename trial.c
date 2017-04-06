#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "linked_list.h"
#include "timer.h"

#define RUN_COUNT 10
#define  N  1000
#define  M  10000
#define  M_MEMBER  0.99
#define  M_INSERT  0.005
#define  M_DELETE  0.005

const char *filename = "info/case1.txt";

int threadcounts[] = {1, 2, 4, 8};
int thread_count = 0;
FILE *f;

float times[RUN_COUNT];


int WriteTextToFile(char *mytext); //trial method
int WriteDoubleToFile(float mytext);

int runserial();

float calculateSD(float data[], float mean);

float calculateMean(float data[]);

int main(int argc, char *argv[]) {

    f = fopen(filename, "a");
    if (f == NULL) {
        printf("Error\n");
        exit(1);
    }
    WriteTextToFile("Case 1: \n");
    for (int mythreadcount = 0; mythreadcount < 4; mythreadcount++) {
        thread_count = threadcounts[mythreadcount];

        WriteTextToFile("\n----------------Thread Count----------------");
        WriteDoubleToFile((float) thread_count);

        float mymean;

        //Run serial
        WriteTextToFile("\n--------Serial-------- \n");
        if (thread_count == 1) {
            for (int runn = 0; runn < RUN_COUNT; runn++) {
                double start, finish, elapsed;
                GET_TIME(start);
                runserial();
                GET_TIME(finish);
                elapsed = finish - start;
                WriteDoubleToFile(elapsed);
                times[runn] = elapsed;
            }
            WriteTextToFile("\nAverage:    ");
            mymean = calculateMean(times);
            WriteDoubleToFile(mymean);
            WriteTextToFile("\nStandard Deviation:    ");
            WriteDoubleToFile(calculateSD(times, mymean));
        }

        //Run Mutex
        WriteTextToFile("\n--------Mutex-------- \n");
        for (int runn = 0; runn < RUN_COUNT; runn++) {
            double start, finish, elapsed;
            GET_TIME(start);
            runserial();
            GET_TIME(finish);
            elapsed = finish - start;
            WriteDoubleToFile(elapsed);
            times[runn] = elapsed;
        }
        WriteTextToFile("\nAverage:    ");
        mymean = calculateMean(times);
        WriteDoubleToFile(mymean);
        WriteTextToFile("\nStandard Deviation:    ");
        WriteDoubleToFile(calculateSD(times, mymean));

        //Run RWLocks
        WriteTextToFile("\n--------Read Write Locks-------- \n");
        for (int runn = 0; runn < RUN_COUNT; runn++) {
            double start, finish, elapsed;
            GET_TIME(start);
            runserial();
            GET_TIME(finish);
            elapsed = finish - start;
            WriteDoubleToFile(elapsed);
            times[runn] = elapsed;
        }
        WriteTextToFile("\nAverage:    ");
        mymean = calculateMean(times);
        WriteDoubleToFile(mymean);
        WriteTextToFile("\nStandard Deviation:    ");
        WriteDoubleToFile(calculateSD(times, mymean));
    }
    printf("fdgfdg");
//    double start, finish, elapsed;
//
//    GET_TIME(start);
//
//    char *mytext = "\n\n Text to fwriiiite";
//
//    WriteTextToFile(mytext);
//    WriteDoubleToFile(6);
//    GET_TIME(finish);
//    elapsed = finish - start;
//
//    printf("   Elapsed time = %e seconds\n", elapsed);
    fclose(f);
}

int WriteTextToFile(char *mytext) {
    fprintf(f, "%s\n", mytext);
}

int WriteDoubleToFile(float mytext) {
    fprintf(f, "%f\n", mytext);
}

float calculateMean(float data[]) {
    float sum = 0.0, mean = 0.0;
    for (int i = 0; i < RUN_COUNT; ++i) {
        sum += data[i];
    }

    mean = sum / RUN_COUNT;
    return mean;
}

float calculateSD(float data[], float mean) {
    float sum = 0.0, standardDeviation = 0.0;

    for (int i = 0; i < RUN_COUNT; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / RUN_COUNT);
}

int runserial() {
    for (int i = 0; i < 10000; i++) {
        int j = i * i * 2;
        float sqr = sqrt(j / RUN_COUNT);
    }
    return 0;
}