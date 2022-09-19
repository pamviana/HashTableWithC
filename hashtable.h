#pragma once // Prevents the header file from loading multiple times

// Constants for the Student Structure
#define EMAIL_SIZE 18
#define NAME_SIZE 24
#define NUMBER_SIZE 10

// Constants for the Hash Table
#define HASH_TABLE_SEGMENTS 7 // Used in the hashing algorithm
#define MOD_SIZE 5 // Used in the hashing algorithm
#define NEW_LINE 10 // Newline character code
#define TABLE_SIZE 35 // Number of available spaces

struct student
{
	char name[NAME_SIZE];
	char number[NUMBER_SIZE];
	char email[EMAIL_SIZE];
	int credits;
	double gpa;
};

int computerHash(char* studentName);
void displayHashTable(struct student* hashTable[]);
void displayRecord(struct student* temp, int index);
void initializeTable(struct student* hashTable[]);
void insertStudent(struct student* hashTable[], struct student* temp);
bool testEmailFormat(struct student temp);
bool testStudentData(struct student temp);

int computerHash(char* studentName)
{ //USE A BETTER HASHING ALGORITHM
int hashValue = 0;
for(int i=0; i < strlen(studentName); i++){
    hashValue += studentName[i];
}
hashValue = (hashValue * HASH_TABLE_SEGMENTS) % (TABLE_SIZE - 1);
return hashValue;
}

void displayHashTable(struct student **hashTable) {
    printf("\n\nHash Table Contents");
    printf("\n-------------------");
    printf("\nIndex  Name                  Number     Email Address      Credits  GPA");
    printf("\n-----  --------------------  ---------  -----------------  -------  ---");

    for(int i=0; i<TABLE_SIZE; i++){
        if(hashTable[i] != NULL){
            printf("\n%5i  %-20s  %9s  %17s  %7i  %0.1f", i, hashTable[i]->name, hashTable[i]->number,
                   hashTable[i]->email, hashTable[i]->credits, hashTable[i]->gpa);
        }
    }
}

void displayRecord(struct student* temp, int index){
    int actualIndex = 0;
    actualIndex = computerHash(temp->name);
    printf("\nAdded Student to Hash Table: %-22s Target %2i, Actual %2i", temp->name, actualIndex, index);

}

void initializeTable(struct student* hashTable[]){
    for (int i=0; i < TABLE_SIZE; i++){
        hashTable[i] = NULL;
    }
}

void insertStudent(struct student* hashTable[], struct student* temp)
{
    int index = 0;
    bool isSpotEmpty = true;
    index = computerHash(temp->name);

    while(isSpotEmpty){
        if(hashTable[index] == NULL){
            hashTable[index] = (struct student*)malloc(sizeof(struct student));
            strcpy(hashTable[index]->name,temp->name);
            strcpy(hashTable[index]->email, temp->email);
            strcpy(hashTable[index]->number, temp->number);
            hashTable[index]->credits = temp->credits;
            hashTable[index]->gpa = temp->gpa;
            displayRecord(hashTable[index], index);
            isSpotEmpty = false;
        } else {
            if(strcmp(hashTable[index]->name, temp->name) == 0){
                displayError(DUPLICATE_NAME, temp->name);
                return;
            }
            index++;
            if(index == (TABLE_SIZE - 1)) {
                index = 0;
            }
        }
    }
}

bool testEmailFormat(struct student temp)
{

    if(temp.email[0] != 'u' || temp.email[9] != '@' || temp.email[13] != '.')
    {
        return false;
    }
    if(temp.email[10] != 'u' || temp.email[11] != 'f' || temp.email[12] != 'b')
    {
        return false;
    }

    if(temp.email[14] != 'e' || temp.email[15] != 'd' || temp.email[16] != 'u'){
        return false;
    }

    return true;
}

bool testStudentData(struct student temp)
{
    if(strlen(temp.name) > 20 || strlen(temp.name) < 5)
    {
        displayError(NAME_LENGTH, temp.name);
        return false;
    }
    if(strlen(temp.number) != 9)
    {
        displayError(NUMBER_LENGTH,temp.number);
        return false;
    }

    if(temp.number[0] != 'u')
    {
        displayError(NUMBER_FORMAT,temp.number);
        return false;
    }
    if(strlen(temp.email) != 17)
    {
        displayError(EMAIL_LENGTH,temp.email);
        return false;
    }
    if(!testEmailFormat(temp))
    {
        displayError(EMAIL_FORMAT,temp.email);
        return false;
    }
    if(temp.credits < 0 || temp.credits > 150)
    {
        char creditsChar[4];
        sprintf(creditsChar, "%d", temp.credits);
        displayError(CREDITS_VALUE, creditsChar);
        return false;
    }
    if(temp.gpa < 0.0 || temp.gpa > 4.0)
    {
        char gpaChar[4];
        sprintf(gpaChar, "%0.1f", temp.gpa);
        displayError(GPA_VALUE, gpaChar);
        return false;
    }

    return true;
}