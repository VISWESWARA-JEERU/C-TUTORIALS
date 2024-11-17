#include <stdio.h>
#include <conio.h>  // For Turbo C++ specific functions like getch()

// Function to solve knapsack using dynamic programming
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[100][100];  // Turbo C++ has smaller memory, so keeping array size reasonable

    // Build table K[][] in a bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = (val[i-1] + K[i-1][w-wt[i-1]]) > K[i-1][w] ? (val[i-1] + K[i-1][w-wt[i-1]]) : K[i-1][w];
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W]; // The maximum value that can be obtained
}

int main() {
    int n, W;

    // Clear the screen (specific to Turbo C++)
    
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[100], wt[100];  // Turbo C++ has limited array sizes
    
    printf("Enter the values of the items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    
    printf("Enter the weights of the items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int maxValue = knapsack(W, wt, val, n);
    printf("Maximum value in knapsack = %d\n", maxValue);

    getch();  // To hold the output screen (specific to Turbo C++)
    return 0;
}