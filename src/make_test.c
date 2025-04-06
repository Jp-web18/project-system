#include "config.h"


/* PASSCODE FUNCTION */
void passCode() {
    printf("%sWelcome to making a quiz module!!%s\n", BLUE, RESET);
    char enteredPasscode[MAX_INPUT];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("%sEnter the passcode: %s", YELLOW, RESET);
        fgets(enteredPasscode, sizeof(enteredPasscode), stdin);
        enteredPasscode[strcspn(enteredPasscode, "\n")] = '\0'; // Remove trailing newline

        if (strcmp(enteredPasscode, PASSCODE) == 0) {
            printf("%sPasscode accepted. Proceeding to make the test answer key.%s\n", GREEN, RESET);
            return; // Exit the function if the passcode is correct
        } else {
            attempts++;
            printf("%sIncorrect passcode. You have %d attempts remaining.%s\n", RED, MAX_ATTEMPTS - attempts, RESET);
        }
    }

    printf("%sToo many incorrect attempts. Access denied to the quiz making module.%s\n", RED, RESET);
    // Optionally, you could add code here to handle the case of failed attempts, like exiting the program.
}



/* TEST MAKING FUNCTION */
void makeTest() {
    // This function will be implemented later
    // Function to create a test
    printf("%sThis function will be implemented later.%s\n", YELLOW, RESET);
}