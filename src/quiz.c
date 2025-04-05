#include "config.h"

#include "quiz.h"
#include "colors.h"
#include "input_validation.h"

/*  */

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

// Function to take answers from students
void takeAnswers(AnswerSheet *sheet) {

    if (sheet->lastQuestion == 0) {
        printf("%sName:\t\t%s ", YELLOW, RESET);
        fgets(sheet->studentName, sizeof(sheet->studentName), stdin);
        sheet->studentName[strcspn(sheet->studentName, "\n")] = 0;

        printf("%sSection code:\t%s ", YELLOW, RESET);
        fgets(sheet->section, sizeof(sheet->section), stdin);
        sheet->section[strcspn(sheet->section, "\n")] = 0;

        printf("%sPC number:\t%s ", YELLOW, RESET);
        fgets(sheet->pcStation, sizeof(sheet->pcStation), stdin);
        sheet->pcStation[strcspn(sheet->pcStation, "\n")] = 0;
    }
    
    char prompt[256];
    sprintf(prompt,
        "%sIs the following information correct? (Y/N)%s\n"
        "Name:\t\t%s\n"
        "Section code:\t%s\n"
        "PC number:\t%s\n"
        "Enter your choice:\t",
        YELLOW, RESET, sheet->studentName, sheet->section, sheet->pcStation
    );
    char confirm = get_yes_no_input(prompt);


    while (confirm == 'N') {
        printf("%sName:\t\t%s ", YELLOW, RESET);
        fgets(sheet->studentName, sizeof(sheet->studentName), stdin);
        sheet->studentName[strcspn(sheet->studentName, "\n")] = 0;

        printf("%sSection code:\t%s ", YELLOW, RESET);
        fgets(sheet->section, sizeof(sheet->section), stdin);
        sheet->section[strcspn(sheet->section, "\n")] = 0;

        printf("%sPC number:\t%s ", YELLOW, RESET);
        fgets(sheet->pcStation, sizeof(sheet->pcStation), stdin);
        sheet->pcStation[strcspn(sheet->pcStation, "\n")] = 0;

        printf("%sIs the following information correct? (Y/N)%s\n", YELLOW, RESET);
        printf("Name:\t\t%s\nSection code:\t%s\nPC number:\t%s\n", sheet->studentName, sheet->section, sheet->pcStation);
        printf("Enter your choice:\t");
        scanf(" %c", &confirm);
        confirm = toupper(confirm);
    }

    time_t startTime = time(NULL);
    FILE *file = fopen("student_data.txt", "a");

    // Check if the file is opened successfully
    if (!file) {
        printf("\n%sERROR: You cannot retake the test!%s\n", RED, RESET);
        return;
    }

    printf("\n\n%sAnswer the following questions:%s\n", GREEN, RESET);
    
    fprintf(file, "Student: %s\nSection: %s\nPC Station: %s\n", sheet->studentName, sheet->section, sheet->pcStation);

    for (int i = sheet->lastQuestion; i < MAX_QUESTIONS; i++) {
        if (difftime(time(NULL), startTime) > TIME_LIMIT * 60) {
            printf("Time is up!\n");
            break;
        }
        printf("%sEnter answer number %s%d%s: ", MAGENTA, BLUE, i + 1, RESET);
        scanf(" %c", &sheet->answers[i]);
        while (getchar() != '\n'); // Clear input buffer

        sheet->answers[i] = toupper(sheet->answers[i]);
        if (sheet->answers[i] == sheet->correctAnswers[i]) {
            sheet->score++;
        }
        fprintf(file, "Q%d: %c (Correct: %c)\n", i + 1, sheet->answers[i], sheet->correctAnswers[i]);

        sheet->lastQuestion = i + 1; // Update last answered question
        saveProgress(sheet); // Save after each question
    }



    sprintf(prompt,
        "%sAre you finished with the test? (Y/N)%s ", YELLOW, RESET);

    confirm = get_yes_no_input(prompt);

    fprintf(file, "\nModified Answers:\n");

    while (confirm == 'N') {
        int questionNumber;
        printf("%sEnter the question number you want to change (1-%d):%s ", YELLOW, MAX_QUESTIONS, RESET);
        scanf("%d", &questionNumber);

        if (questionNumber < 1 || questionNumber > MAX_QUESTIONS) {
            printf("%sInvalid question number!%s\n", RED, RESET);
        } else {
            printf("%sEnter new answer for Question %d:%s ", MAGENTA, questionNumber, RESET);
            scanf(" %c", &sheet->answers[questionNumber - 1]);
            while (getchar() != '\n'); // Clear input buffer
            
            sheet->answers[questionNumber - 1] = toupper(sheet->answers[questionNumber - 1]);

            if (sheet->answers[questionNumber - 1] == sheet->correctAnswers[questionNumber - 1]) {
                sheet->score++;
            } else {
                sheet->score--;
            }
            fprintf(file, "Q%d: %c (Correct: %c)\n", questionNumber, sheet->answers[questionNumber - 1], sheet->correctAnswers[questionNumber - 1]);
        }

        sprintf(prompt,
            "%sAre you finished with the test? (Y/N)%s ", YELLOW, RESET);
    
        confirm = get_yes_no_input(prompt);
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

    printf("Answers saved in student_data.txt\n");
}

