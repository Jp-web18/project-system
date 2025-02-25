#include "../include/quiz.h"
#include "../include/file_manager.h"

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

  /*
  * COMPILE COMMANDS
  * gcc -Iinclude -Wall -g src/main.c src/quiz.c src/file_manager.c -o quiz_system
    
  * RUN COMMANDS
  * ./quiz_system 

*/

int main() {
    AnswerSheet sheet = {0};
    loadCorrectAnswers(&sheet);

    if (loadProgress(&sheet)) {
        printf("Resuming previous session for %s...\n", sheet.studentName);
    } else {
        printf("Starting a new quiz...\n");
    }

    takeAnswers(&sheet);
    printf("Answers saved in student_data.txt\n");

    printf("\nPress any key to exit...\n");
    system("pause");

    return 0;
}