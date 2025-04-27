#include <iostream>
using namespace std;

int main() {
    const int P = 5; // Number of processes
    const int R = 3; // Number of resource types

    // Allocation Matrix (hardcoded)
    int alloc[P][R] = {
        {0, 1, 0}, // P0
        {2,  0, 0}, // P1
        {3, 0, 2}, // P2
        {2, 1, 1}, // P3
        {0, 0, 2}  // P4
    };

    // Max Matrix (hardcoded)
    int max[P][R] = {
        {7, 5, 3}, // P0
        {3, 2, 2}, // P1
        {9, 0, 2}, // P2
        {2, 2, 2}, // P3
        {4, 3, 3}  // P4
    };

    // Available Resources (hardcoded)
    int avail[R] = {3, 3, 2};
    
    // Calculate Need Matrix
    int need[P][R];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Safety Algorithm
    int work[R] = {avail[0], avail[1], avail[2]}; // Copy of available resources
    bool finish[P] = {false}; // Track completed processes
    int safeSeq[P]; // Store safe sequence
    int count = 0; // Count completed processes

    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                // Check if need <= work
                bool canRun = true;
                for (int j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    // Process can run
                    for (int j = 0; j < R; j++)
                        work[j] += alloc[i][j]; // Release resources
                    safeSeq[count] = i; // Add to safe sequence
                    finish[i] = true; // Mark as finished
                    count++;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "The system is in an unsafe state!\n";
            return 0;
        }
    }

    // Print safe sequence
    cout << "The system is in a safe state.\nSafe sequence: ";
    for (int i = 0; i < P; i++)
        cout << "P" << safeSeq[i] << (i < P-1 ? " " : "\n");

    return 0;
}