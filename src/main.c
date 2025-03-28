#include "../include/quiz.h"
#include "../include/file_manager.h"
#include "../include/colors.h"
/*
#include <stdio.h>
#include <stdlib.h>

*/
/*
  * Main function
  * 1. Load correct answers from file
  * 2. Load student progress from file
  * 3. If progress is found, resume the quiz
  * 4. If no progress is found, start a new quiz
  * 5. Take answers from student
  * 6. Save answers to file
  * 7. Exit
  */

// MAIN FUNCTION ENTRY POINT
int main() {
    // system("color 1F");
    AnswerSheet sheet = {0};
    loadCorrectAnswers(&sheet);

    if (loadProgress(&sheet)) {
        printf("%sResuming previous session for %s...%s\n", sheet.studentName, 
            CYAN, RESET);
    } else {
        printf("\n\n%sStarting a new quis...%s\n", CYAN, RESET);
    }

    printf("\n%sTime limit: %d minutes%s\n", YELLOW, TIME_LIMIT, RESET);
    takeAnswers(&sheet);
    printf("Answers saved in student_data.txt\n");

    printf("\nPress any key to exit...\n");
    system("pause");

    return 0;
}
