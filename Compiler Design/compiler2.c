#include <stdio.h>
#include <string.h>

// Function to perform leftmost derivation
void leftmostDerivation(char *input) {
    printf("Leftmost Derivations:\n");
    
    // Step 1: Start with S -> aAB
    printf("Step 1: S -> aAB\n");

    // Step 2: Apply A -> b (leftmost derivation)
    printf("Step 2: aAB -> abB\n");

    // Step 3: Apply B -> c
    printf("Step 3: abB -> abc\n\n");
}

// Function to perform rightmost derivation
void rightmostDerivation(char *input) {
    printf("Rightmost Derivations:\n");

    // Step 1: Start with S -> aAB
    printf("Step 1: S -> aAB\n");

    // Step 2: Apply B -> c (rightmost derivation)
    printf("Step 2: aAB -> aAc\n");

    // Step 3: Apply A -> b
    printf("Step 3: aAc -> abc\n\n");
}

int main() {
    char input[] = "abc";

    // Perform leftmost and rightmost derivations
    leftmostDerivation(input);
    rightmostDerivation(input);

    return 0;
}
