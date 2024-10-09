#include <stdio.h>
#define P 4  // Number of processes
#define R 3  // Number of resource types

int main() {
    // Total Resources A = 10, B = 7, C = 5
    int total_resources[R] = {10, 7, 5};
    
    // Allocation Matrix (how many resources each process holds currently)
    int allocation[P][R] = {
        {0, 1, 0},  // P0
        {2, 0, 0},  // P1
        {3, 0, 2},  // P2
        {2, 1, 1}   // P3
    };
    
    // Maximum Matrix (maximum resources required by each process)
    int max[P][R] = {
        {7, 5, 3},  // P0
        {3, 2, 2},  // P1
        {9, 0, 2},  // P2
        {2, 2, 2}   // P3
    };

    // Available resources after allocation (Total - Allocation)
    int available[R] = {3, 3, 2};

    // Need Matrix (resources still needed by each process to complete)
    int need[P][R];

    // Calculate the Need Matrix
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Safe sequence array to store the result
    int safeSequence[P];
    int finish[P] = {0};  // To check if process is finished or not

    int count = 0;
    while (count < P) {
        int found = 0;
        for (int p = 0; p < P; p++) {
            if (finish[p] == 0) {  // Process not finished
                int canAllocate = 1;
                for (int j = 0; j < R; j++) {
                    if (need[p][j] > available[j]) {
                        canAllocate = 0;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < R; j++) {
                        available[j] += allocation[p][j];  // Release resources
                    }
                    safeSequence[count++] = p;
                    finish[p] = 1;  // Mark process as finished
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state.\n");
            return 0;
        }
    }

    // If the system is in a safe state, print the safe sequence
    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");

    return 0;
}
