#ifndef QUIZ_H
#define QUIZ_H



#define MAX_QUESTIONS 20 // 
#define TIME_LIMIT 60 // Time limit in minutes

typedef struct {
    char studentName[50];
    char section[50];
    char pcStation[10];
    char answers[MAX_QUESTIONS];
    char correctAnswers[MAX_QUESTIONS];
    int score;
    int lastQuestion; // Track progress
} AnswerSheet;

void loadCorrectAnswers(AnswerSheet *sheet);
int loadProgress(AnswerSheet *sheet);
void saveProgress(AnswerSheet *sheet);
void takeAnswers(AnswerSheet *sheet);

#endif // QUIZ_H
