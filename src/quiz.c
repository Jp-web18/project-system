#include "quiz.h"
#include "file_manager.h"

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
        'D'  // number 20
    };
    memcpy(sheet->correctAnswers, tempAnswers, MAX_QUESTIONS);
}

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

        printf("Enter answer number %d: ", i + 1);
        scanf(" %c", &sheet->answers[i]);
        sheet->answers[i] = toupper(sheet->answers[i]);

        if (sheet->answers[i] == sheet->correctAnswers[i]) {
            sheet->score++;
        }
        fprintf(file, "Q%d: %c (Correct: %c)\n", i + 1, sheet->answers[i], sheet->correctAnswers[i]);

        sheet->lastQuestion = i + 1;
        saveProgress(sheet);
    }

    printf("\nQuiz Completed! Your Score: %d/%d\n", sheet->score, MAX_QUESTIONS);
    fprintf(file, "Total Score: %d/%d\n\n", sheet->score, MAX_QUESTIONS);
    fclose(file);
    system("attrib +r student_data.txt");

    if (sheet->lastQuestion >= MAX_QUESTIONS) {
        remove("student_progress.txt");
    }
}