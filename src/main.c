#include "../include/quiz.h"
#include "../include/file_manager.h"
#include "../include/colors.h"


// MAIN FUNCTION ENTRY POINT
int main() {
    // system("color 1F");
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
