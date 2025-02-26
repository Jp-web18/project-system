#include "quiz.h"

// Function to load correct answers into the AnswerSheet structure
void loadCorrectAnswers(AnswerSheet *sheet) {
  char tempAnswers[MAX_QUESTIONS] = {
      'B', // number 1
      'B', // number 2
      'B', // number 3
      'B', // number 4
      'B', // number 5
      'B', // number 6
      'B', // number 7
      'B', // number 8
      'A', // number 9
      'B', // number 10
      'C', // number 11
      'D', // number 12
      'A', // number 13
      'B', // number 14
      'C', // number 15
      'D', // number 16
      'A', // number 17
      'B', // number 18
      'C', // number 19
      'D', // number 20
  };
  memcpy(sheet->correctAnswers, tempAnswers, MAX_QUESTIONS);
}

/*

int loadProgress(AnswerSheet *sheet) {
    FILE *file = fopen("student_progress.txt", "r");
    if (!file) return 0; // No previous progress

    fscanf(file, "%[^\n]\n", sheet->studentName);
    fscanf(file, "%[^\n]\n", sheet->section);
    fscanf(file, "%[^\n]\n", sheet->pcStation);
    fscanf(file, "%d\n", &sheet->lastQuestion);
    fscanf(file, "%d\n", &sheet->score);

    for (int i = 0; i < sheet->lastQuestion; i++) {
        fscanf(file, " %c", &sheet->answers[i]);
    }

    fclose(file);
    return 1; // Progress found
}
*/
/*

void saveProgress(AnswerSheet *sheet) {
    FILE *file = fopen("student_progress.txt", "w");
    if (!file) return;

    fprintf(file, "%s\n%s\n%s\n", sheet->studentName, sheet->section, sheet->pcStation);
    fprintf(file, "%d\n%d\n", sheet->lastQuestion, sheet->score);
    
    for (int i = 0; i < sheet->lastQuestion; i++) {
        fprintf(file, "%c ", sheet->answers[i]);
    }

    fclose(file);
}
*/
// Function to save progress

// Function to take answers from students
void takeAnswers(AnswerSheet *sheet) {
    if (sheet->lastQuestion == 0) {
        printf("Enter your name: ");
        fgets(sheet->studentName, sizeof(sheet->studentName), stdin);
        sheet->studentName[strcspn(sheet->studentName, "\n")] = 0;

        printf("Enter your section: ");
        fgets(sheet->section, sizeof(sheet->section), stdin);
        sheet->section[strcspn(sheet->section, "\n")] = 0;

        printf("Enter your PC Station number: ");
        fgets(sheet->pcStation, sizeof(sheet->pcStation), stdin);
        sheet->pcStation[strcspn(sheet->pcStation, "\n")] = 0;
    }

    time_t startTime = time(NULL);
    FILE *file = fopen("student_data.txt", "a");

    if (!file) {
        printf("ERROR: You cannot retake the test!\n");
        return;
    }

    fprintf(file, "Student: %s\nSection: %s\nPC Station: %s\n", sheet->studentName, sheet->section, sheet->pcStation);

    for (int i = sheet->lastQuestion; i < MAX_QUESTIONS; i++) {
        if (difftime(time(NULL), startTime) > TIME_LIMIT) {
            printf("Time is up!\n");
            break;
        }

        printf("Enter answer for Question %d: ", i + 1);
        scanf(" %c", &sheet->answers[i]);

        sheet->answers[i] = toupper(sheet->answers[i]);
        if (sheet->answers[i] == sheet->correctAnswers[i]) {
            sheet->score++;
        }
        fprintf(file, "Q%d: %c (Correct: %c)\n", i + 1, sheet->answers[i], sheet->correctAnswers[i]);

        sheet->lastQuestion = i + 1; // Update last answered question
        saveProgress(sheet); // Save after each question
    }

    printf("\nQuiz Completed! Your Score: %d/%d\n", sheet->score, MAX_QUESTIONS);
    fprintf(file, "Total Score: %d/%d\n\n", sheet->score, MAX_QUESTIONS);
    fclose(file);

    // Make the file read-only
    system("attrib +r student_data.txt");

    // Delete progress after finishing the quiz
    if (sheet->lastQuestion >= MAX_QUESTIONS) {
        remove("student_progress.txt");
    }
}
