#include <stdio.h>
#define INF 999

int main() {
    int cost[10][10], visited[10] = {0};
    int n, i, j, ne = 1;
    int min, a, b, u, v;
    int total = 0;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost of laying electrical wire between cities (999 for no connection):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[1] = 1; // Start from city 1

    printf("\nConnections for Minimum Cost Electrical Grid:\n");
    while (ne < n) {
        min = INF;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min)
                    if (visited[i] != 0 && visited[j] == 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }

        printf("Connect city %d ? city %d with cost = %d\n", a, b, min);
        total += min;
        visited[b] = 1;
        cost[a][b] = cost[b][a] = INF;
        ne++;
    }

    printf("\n? Minimum Total Cost to Build Electrical Grid = %d\n", total);
    return 0;
}

