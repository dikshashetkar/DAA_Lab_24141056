
#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int marks[], int low, int high) {
    int pivot = marks[high];
    int i = low - 1;
    int j;
    for (j = low; j < high; j++) {
        if (marks[j] <= pivot) {
            i++;
            swap(&marks[i], &marks[j]);
        }
    }
    swap(&marks[i + 1], &marks[high]);
    return (i + 1);
}
void quickSort(int marks[], int low, int high) {
    if (low < high) {
        int pi = partition(marks, low, high);
        quickSort(marks, low, pi - 1);
        quickSort(marks, pi + 1, high);
    }
}
int main() {
    int marks[] = {85, 72, 90, 66, 78, 88};
    int n = sizeof(marks) / sizeof(marks[0]);
    quickSort(marks, 0, n - 1);
    printf("Student marks in ascending order:\n");
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", marks[i]);
    return 0;
}

