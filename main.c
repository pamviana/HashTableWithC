#include "headers.h"

#define INPUT_BUF_SIZE 60 // Size of the buffer used to read records from input file
#define	SEARCH_BUF_SIZE 25 // Size of the buffer used to read records from search file

struct student createStudent(char record[]);
void processInputFile(struct student* hashTable[], char* filename);
void processSearchFile(struct student* hashTable[], char* filename);
bool testRecord(char record[]);

int main(int argc, char *argv[])
{
    if(argc < 1){
        printf("FILENAME NOT FOUND");
    }

    char *fileName = argv[1];
    struct student *hashTable[TABLE_SIZE];

    initializeTable(hashTable);
    processInputFile(hashTable, fileName);
    displayHashTable(hashTable);

    if(argc > 2){
        char *searchFile = argv[2];
        processSearchFile(hashTable, searchFile);
    }

}

struct student createStudent(char record[])
{
    struct student tempStudent;
    const char separator[2] = ",";
    char *credits;
    char *subString;

    subString = strtok(record, separator);

    //get name
    strcpy(tempStudent.name, subString);
    subString = strtok(NULL, separator);

    //get number
    strcpy(tempStudent.number, subString);
    subString = strtok(NULL, separator);

    //get email
    strcpy(tempStudent.email, subString);
    subString = strtok(NULL, separator);

    //get credits
    tempStudent.credits = strtol(subString,&credits,10);
    subString = strtok(NULL, separator);

    //get gpa
    tempStudent.gpa = atof(subString);

    return tempStudent;
}

void processInputFile(struct student* hashTable[], char* filename)
{
    FILE * filePointer;
    char record[INPUT_BUF_SIZE];
    bool isRecordGood;
    bool isStudentDataGood;
    struct student createdStudent;
    int index = 0;

    filePointer = fopen(filename, "r");

    if(filePointer == NULL){
        displayError(FILE_NOT_FOUND, filename);
    }

    printf("\n\nHash Table Log\n--------------");
    while(!feof(filePointer)){
        fgets(record, INPUT_BUF_SIZE, filePointer);
        isRecordGood = testRecord(record);

        if(isRecordGood) {
            createdStudent = createStudent(record);
            isStudentDataGood = testStudentData(createdStudent);

            if(isStudentDataGood){
                insertStudent(hashTable, &createdStudent);
            }
        }
        index++;
    }

    fclose(filePointer);
	// Do not forget to use the following functions:
	// memset() - fill the buffer array with the specified character
}

void processSearchFile(struct student* hashTable[], char* filename)
{
    FILE * filePointer;
    char search[SEARCH_BUF_SIZE];
    char *type;
    char *string;

    filePointer = fopen(filename, "r");

    if(filePointer == NULL){
        displayError(FILE_NOT_FOUND, filename);
    }
    printf("\n\nSearch Results");
    printf("\n--------------");

    while(!feof(filePointer)){
        fgets(search, SEARCH_BUF_SIZE, filePointer);
        type = strtok(search, ",");

        string = strtok(NULL, ",");

        performSearch(hashTable, type, string);
    }
}

bool testRecord(char record[])
{
    int totalCommas = 0;
    int size = strlen(record);

    if(strlen(record) < 3){
        displayError(BLANK_RECORD, record);
        return false;
    }

    if(strlen(record) < 35 || strlen(record) > 60){

        record[size-1] = '\0';
        displayError(SHORT_RECORD, record);
        return false;
    }

    for(int i=0; i< strlen(record); i++)
    {
        if(record[i] == ','){
            totalCommas++;
        }
    }

    if(totalCommas != 4)
    {
        record[size-1] = '\0';
        displayError(CORRUPT_RECORD, record);
        return false;
    }
    return true;
}