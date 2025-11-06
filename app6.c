#include <stdio.h>
#define INF 999

void dijkstra(int n, int cost[10][10], int src) {
    int dist[10], visited[10] = {0};
    int i, j, count, min, next;

    for (i = 1; i <= n; i++)
        dist[i] = cost[src][i];

    visited[src] = 1;
    dist[src] = 0;
    count = 1;

    while (count < n - 1) {
        min = INF;
        for (i = 1; i <= n; i++)
            if (dist[i] < min && !visited[i]) {
                min = dist[i];
                next = i;
            }

        visited[next] = 1;
        for (i = 1; i <= n; i++)
            if (!visited[i])
                if (min + cost[next][i] < dist[i])
                    dist[i] = min + cost[next][i];

        count++;
    }

    printf("\nShortest path from Router %d to other Routers:\n", src);
    for (i = 1; i <= n; i++)
        if (i != src)
            printf("Router %d ? Router %d = %d ms\n", src, i, dist[i]);
}

int main() {
    int n, i, j, src;
    int cost[10][10];

    printf("Enter number of Routers: ");
    scanf("%d", &n);

    printf("Enter network link cost matrix (999 for no connection):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source Router number: ");
    scanf("%d", &src);

    dijkstra(n, cost, src);
    return 0;
}

