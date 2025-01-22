#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    const char *prompt;
    const char *subject;
} PromptSubject;


int main() {
  PromptSubject data[] = {
    { "[1] Math grade: ", "Math" },
    { "[2] English grade: ", "English" },
    { "[3] Programming grade: ", "Programming" },
    { "[4] HCI grade: ", "HCI" },
    { "[5] CWTS grade: ", "CWTS" }
    // { "[6] Earth grade: ", "Earth" }
  };

  // Total size of the array in bytes
  size_t total_size = sizeof(data);
  // Size of a single element
  size_t element_size = sizeof(data[0]);
  // Number of elements in the array
  size_t num_elements = total_size / element_size;
  float grades[num_elements];
  char valInputs[12];


  printf("Enter grades each subject prompts\n");
  for (int i = 0; i < sizeof(grades) / sizeof(grades[0]); i++) {
    printf("%s", data[i].prompt);
    while (true) {
      if (fgets(valInputs, sizeof(valInputs), stdin)) {
        if (valInputs[0] == '\n') {
          printf("\nInvalid empty grade input!\n");
          printf("%s", data[i].prompt);
        } else if (sscanf(valInputs, "%f", &grades[i])) {
          break;
        } else {
          printf("\nInvalid entry grade input!\n");
          printf("%s", data[i].prompt);
        }
      }
    }
  }

  printf("\n");
  for (int i = 0; i < sizeof(grades) / sizeof(grades[0]); i++) {
    printf("%s grade: %.2f\n", data[i].subject, grades[i]);
  }



  return 0;
}
