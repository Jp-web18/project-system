#include "../include/config.h"

#define MAX_INPUTS 10 // Maximum input size for answers


// MAIN FUNCTION ENTRY POINT
int main() {
    char choice[MAX_INPUTS];
    int running = 1;

    while (running) {
        // Display the welcome message and options
        printf("%s=====================================%s\n", YELLOW, RESET);
        printf("%s      Welcome to the Quiz System%s\n", YELLOW, RESET);
        printf("%s=====================================%s\n", YELLOW, RESET);
        printf("%s[1] Make a test%s\n", YELLOW, RESET);
        printf("%s[2] Take the test%s\n", YELLOW, RESET);
        printf("%s[3] Exit%s\n", YELLOW, RESET);
        printf("%s=====================================%s\n", YELLOW, RESET);
        printf("%sEnter your choice:\t%s", YELLOW, RESET);

        // Read the user's choice securely
        fgets(choice, sizeof(choice), stdin);
        // Remove the newline character if present
        choice[strcspn(choice, "\n")] = '\0';

        // Process the user's choice
        if (strcmp(choice, "1") == 0) {
            passCode();
            makeTest();
        } else if (strcmp(choice, "2") == 0) {
            AnswerSheet sheet = {0};
            loadCorrectAnswers(&sheet);

            if (loadProgress(&sheet)) {
                printf("%sResuming previous session for %s...%s\n", sheet.studentName, CYAN, RESET);
            } else {
                printf("\n\n%sStarting a new quis...%s\n", CYAN, RESET);
            }

            printf("\n%sTime limit: %d minutes%s\n", YELLOW, TIME_LIMIT, RESET);
            takeAnswers(&sheet);
        } else if (strcmp(choice, "3") == 0) {
            printf("Exiting the system.\n");
            running = 0;
        } else {
            printf("\n%sInvalid choice.%s\n", RED, RESET);
            printf("Please enter a valid option (1, 2, or 3).\n");
        }
    }

    printf("\nPress any key to exit...\n");
    system("pause");

    return 0;
}