#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
	char prompts[][50] = {
		"Enter a number: ",
		"Enter another number: ",
		"Enter again a number: "
	};
	char inputVal[10];
	int num[3];
	
	printf("Enter a number: ");
	for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
		while (true) {
			if (fgets(inputVal, sizeof(inputVal), stdin)) {
				if (inputVal[0] == '\n') {
					printf("Empty input. Enter a number: ");
					continue;
				} else if (sscanf(inputVal, "%d", &num[i])) {
					break;
				} else {
					printf("Invalid input. Enter a number: ");
				}
			}
		}
		/* code */
	}
	
	for (size_t i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
		printf("You entered: %d\n", num[i]);
		/* code */
	}
	
	printf("You entered: %d\n", num);
	

	return 0;
}