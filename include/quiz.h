#ifndef QUIZ_H
#define QUIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_QUESTIONS 20
#define TIME_LIMIT 60

typedef struct {
    char studentName[50];
    char section[50];
    char pcStation[10];
    char answers[MAX_QUESTIONS];
    char correctAnswers[MAX_QUESTIONS];
    int score;
    int lastQuestion;
} AnswerSheet;

void loadCorrectAnswers(AnswerSheet *sheet);
void takeAnswers(AnswerSheet *sheet);

#endif // QUIZ_H
