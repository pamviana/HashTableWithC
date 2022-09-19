#pragma once // Prevents the header file from loading multiple times

void displayError(int error, char* errorInfo);

enum ErrorMessage {
    MISSING_COMMAND_ARGUMENT,
    FILE_NOT_FOUND,
    BLANK_RECORD,
    CORRUPT_RECORD,
    SHORT_RECORD,
    DUPLICATE_NAME,
    NAME_LENGTH,
    NUMBER_LENGTH,
    NUMBER_FORMAT,
    EMAIL_LENGTH,
    EMAIL_FORMAT,
    CREDITS_VALUE,
    GPA_VALUE
};

void displayError(int error, char* errorInfo)
{
    printf("\nError: ");
    switch (error) {
        case MISSING_COMMAND_ARGUMENT:
            printf("The program expects at least one (1) argument (%s)", errorInfo);
            break;
        case FILE_NOT_FOUND:
            printf("The program is unable to open the provided file (%s)", errorInfo);
            break;
        case BLANK_RECORD:
            printf("Blank Line Found");
            break;
        case CORRUPT_RECORD:
            printf("Corrupt Record %s", errorInfo);
            break;
        case SHORT_RECORD:
            printf("Short Record %s", errorInfo);
            break;
        case DUPLICATE_NAME:
            printf("An attempt was made to add a student with the same name to the hash table (%s)", errorInfo);
            break;
        case NAME_LENGTH:
            printf("Student Name Not Between 5 and 20 Characters (%s)", errorInfo);
            break;
        case NUMBER_LENGTH:
            printf("Student Number Not 9 Characters (%s)", errorInfo);
            break;
        case NUMBER_FORMAT:
            printf("Student Number Is Invalid (%s)", errorInfo);
            break;
        case EMAIL_LENGTH:
            printf("Student Email Not 17 Characters (%s)", errorInfo);
            break;
        case EMAIL_FORMAT:
            printf("Student Email Format Is Invalid (%s)", errorInfo);
            break;
        case CREDITS_VALUE:
            printf("Student Credit Not Less Than 150 (%s)", errorInfo);
            break;
        case GPA_VALUE:
            printf("Student GPA Not Less Than 4.0 (%s)", errorInfo);
            break;
        default:
            printf("ERROR NOT FOUND");
            break;
    }
}