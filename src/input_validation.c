#include "config.h"


#include "input_validation.h"
#include "colors.h"

/* INPUT VALIDATIONS FOR MAIN PAGE */


<<<<<<< HEAD

/* INPUT VALIDATIONS FOR ADMINISTRATOR PERSPECTIVE */


/* STUDENT PERSPECTIVE INPUT VALIDATIONS */
=======
>>>>>>> 1c8e171446c6f969e21b4f56f6395a0f25f0812f
char get_yes_no_input(const char *prompt) {
    char buffer[10];
    char confirm;
    
    do {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading input.\n");
            exit(EXIT_FAILURE);
        }

        // Remove newline character from the input
        

        buffer[strcspn(buffer, "\n")] = 0;

        if (buffer[0] != '\0') {
            buffer[0] = toupper(buffer[0]);

            if (buffer[0] == 'Y' || buffer[0] == 'N') {
                confirm = buffer[0];
            } else {
                printf("%sInvalid input! Please enter either 'Y' or 'N'.%s\n\n", RED, RESET);
            }
        } else {
            printf("%sInvalid input! Please enter either 'Y' or 'N'.%s\n\n", RED, RESET);
        }
    } while (confirm != 'Y' && confirm != 'N');

    return confirm;
}

