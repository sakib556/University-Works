#include <stdio.h>
#include <string.h>

// Function to find the first occurrence of a non-terminal (Leftmost)
int findLeftmostNonTerminal(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'S' || str[i] == 'A' || str[i] == 'B') {
            return i;
        }
    }
    return -1; // No non-terminal found
}

// Function to find the last occurrence of a non-terminal (Rightmost)
int findRightmostNonTerminal(char *str) {
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == 'S' || str[i] == 'A' || str[i] == 'B') {
            return i;
        }
    }
    return -1; // No non-terminal found
}

// Function to apply Leftmost or Rightmost derivation
void derive(char *input, int isLeftmost) {
    int step = 0;
   // printf("Step %d: %s\n", step, input);

    while (1) {
        int pos;
        if (isLeftmost)
            pos = findLeftmostNonTerminal(input);
        else
            pos = findRightmostNonTerminal(input);

        if (pos == -1) {
            break; // No non-terminal left, derivation is complete
        }

        // Apply the grammar rule based on the non-terminal found
        char nonTerminal = input[pos];
        char newString[100] = "";

        if (nonTerminal == 'S') {
            // Apply S -> aAB
            strncat(newString, input, pos);   // Copy left part
            strcat(newString, "aAB");         // Apply production
            strcat(newString, &input[pos+1]); // Copy right part
        }
        else if (nonTerminal == 'A') {
            // Apply A -> b (you can change to apply ε if needed)
            strncat(newString, input, pos);
            strcat(newString, "b");           // Apply production A -> b
            strcat(newString, &input[pos+1]);
        }
        else if (nonTerminal == 'B') {
            // Apply B -> c (you can change to apply ε if needed)
            strncat(newString, input, pos);
            strcat(newString, "c");           // Apply production B -> c
            strcat(newString, &input[pos+1]);
        }

        strcpy(input, newString); // Update the string
        printf("Step %d: %s\n", ++step, input);
    }
}

// Function to run both leftmost and rightmost derivations
void runDerivations() {
    char inputLeftmost[100] = "S"; // Start symbol (initial input string) for leftmost derivation
    char inputRightmost[100] = "S"; // Start symbol for rightmost derivation

    // Leftmost Derivation
    printf("Leftmost Derivations:\n");
    derive(inputLeftmost, 1); // 1 for Leftmost

    // Rightmost Derivation
    printf("\nRightmost Derivations:\n");
    derive(inputRightmost, 0); // 0 for Rightmost
}

int main() {
    runDerivations(); // Run both derivations
    return 0;
}
