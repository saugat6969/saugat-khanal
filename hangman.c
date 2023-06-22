#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRIES 6

// Function to clear input buffer
void clearInputBuffer() {
    while (getchar() != '\n') {
        continue;
    }
}

int main() {
    char word[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    int numTries = 0;
    int wordLength;
    int i, j, found, won;

    printf("Welcome to Hangman!\n");

    // Get the word to be guessed
    printf("Enter the word to be guessed (up to %d characters): ", MAX_WORD_LENGTH);
    fgets(word, MAX_WORD_LENGTH, stdin);
    wordLength = strlen(word) - 1;

    // Clear input buffer
    clearInputBuffer();

    // Convert the word to lowercase
    for (i = 0; i < wordLength; i++) {
        word[i] = tolower(word[i]);
    }

    // Initialize the guessed array
    for (i = 0; i < wordLength; i++) {
        guessed[i] = '_';
    }

    // Start the game loop
    while (numTries < MAX_TRIES) {
        printf("\n");

        // Print the guessed word
        for (i = 0; i < wordLength; i++) {
            printf("%c ", guessed[i]);
        }
        printf("\n");

        // Get the player's guess
        printf("Enter your guess (a single letter): ");
        char guess;
        scanf("%c", &guess);
        clearInputBuffer();

        // Convert the guess to lowercase
        guess = tolower(guess);

        // Check if the guess is correct
        found = 0;
        for (i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                found = 1;
            }
        }

        if (found) {
            printf("Correct guess!\n");
        } else {
            numTries++;
            printf("Incorrect guess! You have %d tries left.\n", MAX_TRIES - numTries);
        }

        // Check if the player has won
        won = 1;
        for (i = 0; i < wordLength; i++) {
            if (guessed[i] == '_') {
                won = 0;
                break;
            }
        }

        if (won) {
            printf("\nCongratulations! You won!\n");
            printf("The word was: %s\n", word);
            break;
        }
    }

    if (numTries >= MAX_TRIES) {
        printf("\nGame over! You lost!\n");
        printf("The word was: %s\n", word);
    }

    return 0;
}

