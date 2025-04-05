#include "config.h"



/* QUIZ FILE MANAGEMENT */
int loadProgress(AnswerSheet *sheet) {
    FILE *file = fopen("student_progress.dat", "r");
    if (!file) return 0;

    fscanf(file, "%[^\n]\n", sheet->studentName);
    fscanf(file, "%[^\n]\n", sheet->section);
    fscanf(file, "%[^\n]\n", sheet->pcStation);
    fscanf(file, "%d\n", &sheet->lastQuestion);
    fscanf(file, "%d\n", &sheet->score);

    for (int i = 0; i < sheet->lastQuestion; i++) {
        fscanf(file, " %c", &sheet->answers[i]);
    }
    
    fclose(file);
    return 1;
}

void saveProgress(AnswerSheet *sheet) {
    FILE *file = fopen("student_progress.dat", "w");
    if (!file) return;

    fprintf(file, "%s\n%s\n%s\n", sheet->studentName, sheet->section, sheet->pcStation);
    fprintf(file, "%d\n%d\n", sheet->lastQuestion, sheet->score);

    for (int i = 0; i < sheet->lastQuestion; i++) {
        fprintf(file, "%c ", sheet->answers[i]);
    }

    fclose(file);
}



/* MAKE QUIZ FILE MANAGEMENT */
    