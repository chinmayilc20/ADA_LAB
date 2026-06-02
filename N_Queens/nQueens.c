#include <stdio.h>
#include <stdbool.h>

bool place(int x[], int k);
void printSolution(int x[], int n);
void nQueens(int n);

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nQueens(n);
    return 0;
}

void nQueens(int n) {
    int x[20] = {0};
    int k = 1;
    int count = 0;

    while (k != 0) {
        x[k] = x[k] + 1;

        while (x[k] <= n && !place(x, k)) {
            x[k] = x[k] + 1;
        }

        if (x[k] <= n) {
            if (k == n) {
                printSolution(x, n);
                printf("Solution found\n");
                count++;
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }

    printf("Total solutions: %d\n", count);
}

bool place(int x[], int k) {
    for (int i = 1; i < k; i++) {
        if (x[i] == x[k] || (i - x[i]) == (k - x[k]) || (i + x[i]) == (k + x[k])) {
            return false;
        }
    }
    return true;
}

void printSolution(int x[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}