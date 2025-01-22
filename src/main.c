#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
  const char *promptsForInfo[] = {
    "Enter your favorite number: ",
    "Enter age: ",
    "Enter years of experience: ",
    "Enter grade: ",
    "Enter number of siblings: "
  };
  float info[5];
  char inputVal[10];

  printf("Enter basic informations:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s", promptsForInfo[i]);
    // scanf("%f", &grades[i]);
    while (true) {
      if (fgets(inputVal, sizeof(inputVal), stdin)) {
        if (inputVal[0] == '\n') {
          printf("\nInvalid empty input! Enter again.\n");
          printf("%s", promptsForInfo[i]);
          continue;
          // printf("%s", subjects[i]);
        } else if (sscanf(inputVal, "%f", &info[i])) {
          break;
        }
      }

      printf("\nInvalid info entry! Enter another valid info.\n");
      printf("%s", promptsForInfo[i]);
    }
  }

  char *infoNames[] = {
		"\nFavorite number",
		"Age",
		"Years of experience",
		"Grade",
		"Number of siblings"
	};

	for (int i = 0; i < 5; i++) {
		printf("%s: %.2f\n", infoNames[i], info[i]);
	}

  return 0;
}