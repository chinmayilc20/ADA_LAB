#include <stdio.h>

// Structure for an item
struct Item {
    int value, weight;
};

// Function to compare items based on value/weight ratio
int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return r2 > r1 ? 1 : -1;
}

// Function to solve fractional knapsack
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort items by value/weight ratio
    qsort(arr, n, sizeof(arr[0]), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        // If adding full item doesn't exceed capacity
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            // Take fraction of item
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

// Driver code
int main() {
    int W = 50; // Knapsack capacity

    struct Item arr[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    double maxValue = fractionalKnapsack(W, arr, n);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}