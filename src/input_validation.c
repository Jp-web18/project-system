#include "config.h"


#include "input_validation.h"
#include "colors.h"

/* INPUT VALIDATIONS FOR MAIN PAGE */



/* INPUT VALIDATIONS FOR ADMINISTRATOR PERSPECTIVE */


/* STUDENT PERSPECTIVE INPUT VALIDATIONS */
char get_yes_no_input(const char *prompt) {
    char buffer[10];
    char confirm;
    
    do {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading input.\n");
            exit(EXIT_FAILURE);
        }

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

