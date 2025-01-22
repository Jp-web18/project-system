#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// FUNCTION DEFNITION

// adding sum of all input grades
float sumOfGrades(float grades[], int subCount);

// calculating the total average of all grades
float avGrades(float totalSum, int countOfSub);

// input validation
void getValidatedNumber(const char *prompt, float *number);


// MAIN FUNCTION FOR ENTRY POINT
int main() {
  char inputVal[10];
  float subGrades[5];
  const char subjectsPrompts[][50] = {
    "[1] Enter grade in Math: ",
    "[2] Enter grade in English: ",
    "[3] Enter grade in History: ",
    "[4] Enter grade in Programming: ",
    "[5] Enter grade in HCI: "
  };

  printf("-------------------------------------------------------------\n");
  printf("Enter all your grades with the following subjects below.\n");

  // Calling getValidatedNumber for each subject
  for (int i = 0; i < 5; i++) {
    getValidatedNumber(subjectsPrompts[i], &subGrades[i]);
  }


  float sumGrades = sumOfGrades(subGrades, sizeof(subGrades) / sizeof(subGrades[0]));
  float average = avGrades(sumGrades, sizeof(subGrades) / sizeof(subGrades[0]));


  printf("\nTotal sum of grades is %.2f.\n", sumGrades);
  printf("Average of grades is %.2f.\n", average);


  return 0;
}

// FUNCTION DEFNITION

// input validation
void getValidatedNumber(const char *prompt, float *number) {
  char inputVal[50];

  while (true) {
    printf("%s", prompt);
    if (fgets(inputVal, sizeof(inputVal), stdin)) {
      if (inputVal[0] == '\n') {
        printf("\nInvalid input! Try again.\n");
        continue;
      } else if (sscanf(inputVal, "%f", number)) {
        printf("\n");
        break;
      }
    }
    printf("\nInvalid input. Try again.\n");
  }
}

// adding sum of all input grades
float sumOfGrades(float grades[], int subCount) {
  float totalNumGrades = 0;

  for (int i = 0; i < subCount; i++) {
    totalNumGrades += grades[i];
  }

  return totalNumGrades;
}

// calculating the total average of all grades
float avGrades(float totalSum, int countOfSub) {
  return totalSum / countOfSub;
}
