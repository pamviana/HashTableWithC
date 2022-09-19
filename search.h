#pragma once // Prevents the header file from loading multiple times

void performSearch(struct student* array[], char* type, char* string);

enum SearchOperation {
    CREDITS,
    CREDITS_LESS,
    CREDITS_MORE,
    EMAIL,
    EMAIL_PART,
    NAME_FULL,
    NAME_FIRST,
    NAME_LAST,
    GPA,
    GPA_LESS,
    GPA_MORE,
    NUMBER,
    NUMBER_PART
};

void printSearch(struct student* hashTable){
    printf("\n       %-20s  %9s  %17s  %7i  %0.1f", hashTable->name, hashTable->number,
           hashTable->email, hashTable->credits, hashTable->gpa);
}

void performSearch(struct student* array[], char* type, char* string)
{
    switch (atoi(type)) {
    case CREDITS:
        printf("\nSearching Records Where Credits Is %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(array[i]->credits == atoi(string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case CREDITS_LESS:
        printf("\nSearching Records Where Credits < %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(array[i]->credits < atoi(string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case CREDITS_MORE:
        printf("\nSearching Records Where Credits > %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(array[i]->credits > atoi(string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case EMAIL:
        printf("\nSearching Records Where Email Is %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(strcmp(array[i]->email, string) == 0){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case EMAIL_PART:
        printf("\nSearching Records Where Email Contains %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(strstr(array[i]->email, string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case NAME_FULL:
        printf("\nSearching Records Where Full Name Is %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(strstr(array[i]->name, string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case NAME_FIRST:
        printf("\nSearching Records Where First Name Is %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(strstr(array[i]->name, string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case NAME_LAST:
        printf("\nSearching Records Where Last Name Is %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(strstr(array[i]->name, string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case GPA:
        printf("\nSearching Records Where GPA Is %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(array[i]->gpa == atof(string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case GPA_LESS:
        printf("\nSearching Records Where GPA < %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(array[i]->gpa < atof(string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case GPA_MORE:
        printf("\nSearching Records Where GPA > %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(array[i]->gpa > atof(string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case NUMBER:
        printf("\nSearching Records Where Student Number Is %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(strcmp(array[i]->number, string) == 0){
                    printSearch(array[i]);
                }
            }
        }
        break;
    case NUMBER_PART:
        printf("\nSearching Records Where Student Number Contains %s:", string);
        for(int i=0; i< TABLE_SIZE; i++) {
            if(array[i] != NULL){
                if(strstr(array[i]->number, string)){
                    printSearch(array[i]);
                }
            }
        }
        break;
    }
}