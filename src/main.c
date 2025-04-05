#include "../include/config.h"

#include "../include/quiz.h"
#include "../include/file_manager.h"
#include "../include/colors.h"


#define MAX_INPUT 10 // Maximum input size for answers


// MAIN FUNCTION ENTRY POINT
int main() {
    char choice[MAX_INPUT];

    // Display the welcome message and options
    printf("=====================================\n");
    printf("     Welcome to the Quiz System\n");
    printf("=====================================\n");
    printf("[1] Make a test\n");
    printf("[2] Take the test\n");
    printf("Enter your choice:\t");

    // Read the user's choice securely
    fgets(choice, sizeof(choice), stdin);
    // Remove the newline character if present
    choice[strcspn(choice, "\n")] = '\0';

    // Process the user's choice
    if (strcmp(choice, "1") == 0) {
        printf("You chose to make a test.\n");
    } else if (strcmp(choice, "2") == 0) {
        printf("You chose to take the test.\n");
    } else {
        printf("Invalid choice.\n");
    }




    AnswerSheet sheet = {0};
    loadCorrectAnswers(&sheet);

    if (loadProgress(&sheet)) {
        printf("%sResuming previous session for %s...%s\n", sheet.studentName, CYAN, RESET);
    } else {
        printf("\n\n%sStarting a new quis...%s\n", CYAN, RESET);
    }

    printf("\n%sTime limit: %d minutes%s\n", YELLOW, TIME_LIMIT, RESET);
    takeAnswers(&sheet);

    printf("\nPress any key to exit...\n");
    system("pause");

    return 0;
}
