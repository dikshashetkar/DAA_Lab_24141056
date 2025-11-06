#include <stdio.h>                                                                                                            Roll No:24141056
#include <string.h>
int binarySearch(char contacts[][20], int low, int high, char name[]) {
    if (low <= high) {
        int mid = (low + high) / 2;
        int res = strcmp(contacts[mid], name);
        if (res == 0)
            return mid;
        else if (res > 0)
            return binarySearch(contacts, low, mid - 1, name);
        else
            return binarySearch(contacts, mid + 1, high, name);
    }
    return -1;
}
int main() {
    char contacts[][20] = {"Aarav", "Diksha", "Karan", "Neha", "Priya", "Ravi", "Vikas"};
    int n = sizeof(contacts) / sizeof(contacts[0]);
    char name[20];
    int result;
    printf("Enter name to search: ");
    scanf("%s", name);
    result = binarySearch(contacts, 0, n - 1, name);
    if (result == -1)
        printf("Contact not found!\n");
    else
        printf("Contact found at position %d.\n", result + 1);
    return 0;
}

