#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "linked_list.h"

int WriteToFile(); //trial method

int main(int argc, char *argv[]) {
    WriteToFile();
}

int WriteToFile() {
    FILE *f;
    f = fopen("file.txt", "w+");
    if (f == NULL) {
        printf("Error\n");
        exit(1);
    }
    const char *text = "Some Text";
    fprintf(f, "Text written: %s\n", text);

    int i = 9;
    float ff = 2.34234;
    char c = 'S';

    fprintf(f, "Integer: %d\nFloat: %f\nChar: %c", i, ff, c);
    fclose(f);
}
