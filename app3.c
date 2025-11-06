#include <stdio.h>

// Function to perform investment selection using Greedy method
void investmentSelection(int n, float cost[], float profit[], float budget) {
    float ratio[20], x[20];
    float total_profit = 0.0;
    int i, j;
    float temp, remaining_budget;

    // Calculate profit-to-cost ratio
    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / cost[i];

    // Sort by ratio in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                temp = cost[i]; cost[i] = cost[j]; cost[j] = temp;
                temp = profit[i]; profit[i] = profit[j]; profit[j] = temp;
            }
        }
    }

    // Initialize all fractions as 0
    for (i = 0; i < n; i++)
        x[i] = 0.0;

    remaining_budget = budget;

    // Select investments
    for (i = 0; i < n; i++) {
        if (cost[i] > remaining_budget)
            break;
        else {
            x[i] = 1.0;
            total_profit += profit[i];
            remaining_budget -= cost[i];
        }
    }

    // Take fractional part of next investment (if possible)
    if (i < n)
        x[i] = remaining_budget / cost[i];
    total_profit += x[i] * profit[i];

    // Display results
    printf("\nSelected Investment Fractions:\n");
    for (i = 0; i < n; i++)
        printf("Investment %d: %.2f\n", i + 1, x[i]);

    printf("\nMaximum Expected Profit: %.2f\n", total_profit);
}

int main() {
    int n, i;
    float cost[20], profit[20], budget;

    printf("Enter number of investment options: ");
    scanf("%d", &n);

    printf("\nEnter investment cost and expected profit for each option:\n");
    for (i = 0; i < n; i++) {
        printf("Investment %d cost: ", i + 1);
        scanf("%f", &cost[i]);
        printf("Investment %d expected profit: ", i + 1);
        scanf("%f", &profit[i]);
    }

    printf("\nEnter total available budget: ");
    scanf("%f", &budget);

    investmentSelection(n, cost, profit, budget);

    return 0;
}

