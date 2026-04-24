#include <stdio.h>
int countWays(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0 || n == 1) {
        return 1;
    }

    return countWays(n - 1) + countWays(n - 2);
}

void printPaths(int n, int path[], int pathLen) {
    if (n < 0) {
        return;
    }

    if (n == 0) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d", path[i]);
            if (i < pathLen - 1) {
                printf("+");
            }
        }
        printf("\n");
        return;
    }

    path[pathLen] = 1;
    printPaths(n - 1, path, pathLen + 1);
    path[pathLen] = 2;
    printPaths(n - 2, path, pathLen + 1);
}
int main() {
    int N;

    printf("Enter the maze position N (1 to 15): ");
    if (scanf("%d", &N) != 1 || N < 1 || N > 15) {
        printf("Invalid input. Please run the program again and enter a number between 1 and 15.\n");
        return 1;
    }
    int totalWays = countWays(N);
    printf("\nTotal distinct ways to reach position %d: %d\n", N, totalWays);
    printf("All unique path sequences:\n");
    int path[15];
    printPaths(N, path, 0);

    return 0;
}
