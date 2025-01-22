
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char wordInput[30];
    
    printf("Enter 'yes' or 'no' (30 limit): "); 
    fgets(wordInput, sizeof(wordInput), stdin);
    wordInput[strlen(wordInput) - 1] = '\0';
    
    while (strlen(wordInput) == 0) {
        printf("\nYou did not enter any word!\n");
        printf("Enter 'yes' or 'no' (30 limit): ");
        fgets(wordInput, sizeof(wordInput), stdin);
        wordInput[strlen(wordInput) - 1] = '\0';
    }

    while (strcasecmp(wordInput, "yes") != 0 && strcasecmp(wordInput, "no") != 0) {
        printf("\nInvalid input! Please enter 'yes' or 'no': ");
        fgets(wordInput, sizeof(wordInput), stdin);
        wordInput[strlen(wordInput) - 1] = '\0';
        
        while (strlen(wordInput) == 0) {
            printf("\nYou did not enter any word!\n");
            printf("Enter 'yes' or 'no' (30 limit): ");
            fgets(wordInput, sizeof(wordInput), stdin);
            wordInput[strlen(wordInput) - 1] = '\0';
        }
    }
    
    printf("\nYou entered \"%s\"\n", wordInput);
    
    return 0;
}
