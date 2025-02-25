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
  * gcc -I../include -Wall -g src/main.c src/quiz.c src/file_manager.c -o quiz_system
  
  * RUN COMMANDS
  * gdb ./quiz_system 

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
    return 0;
}