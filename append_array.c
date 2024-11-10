#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append(int *a1, int *a2, int n1, int n2) {
    for (int i = 0; i < n2; i++) {
        a1[n1 + i] = a2[i];
    }
}

int main() {
    int n1, n2;
    printf("Enter number of elements in array 1: ");
    scanf("%d", &n1);
    int *a1 = (int *)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        scanf("%d", &a1[i]);
    }

    printf("Enter number of elements in array 2: ");
    scanf("%d", &n2);
    int *a2 = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        scanf("%d", &a2[i]);
    }

    a1 = realloc(a1, (n1 + n2) * sizeof(int));
    append(a1, a2, n1, n2);

    printf("Appended array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d\t", a1[i]);
    }
    free(a1);
    free(a2);

    return 0;
}
