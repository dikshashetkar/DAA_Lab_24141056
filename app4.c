#include <stdio.h>
#define MAX 20

// Function to find the smallest two files
void findTwoMin(int files[], int n, int *min1, int *min2) {
    int i;
    int first = 9999, second = 9999;
    *min1 = *min2 = -1;

    for (i = 0; i < n; i++) {
        if (files[i] != 0) {
            if (files[i] < first) {
                second = first;
                *min2 = *min1;
                first = files[i];
                *min1 = i;
            } else if (files[i] < second) {
                second = files[i];
                *min2 = i;
            }
        }
    }
}

int main() {
    int n, i, total_cost = 0;
    int files[MAX], min1, min2, temp;

    printf("Enter number of database files: ");
    scanf("%d", &n);

    printf("Enter the sizes of the files (in MB):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &files[i]);
    }

    int remaining = n;
    printf("\n--- Database File Merge Process ---\n");
    while (remaining > 1) {
        findTwoMin(files, n, &min1, &min2);

        temp = files[min1] + files[min2];
        total_cost += temp;

        printf("Merging files of sizes %dMB and %dMB ? cost = %dMB\n",
               files[min1], files[min2], temp);

        files[min1] = temp;
        files[min2] = 0; // mark merged file as used
        remaining--;
    }

    printf("\n? Minimum Total Merge Cost = %dMB\n", total_cost);
    return 0;
}

