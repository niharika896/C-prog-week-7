#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int threeFibo(int a, int b, int c, int n) {
    if (n == 1) return a;
    if (n == 2) return b;
    if (n == 3) return c;
    return threeFibo(b, c, a + b + c, n - 1);
}

int main() {
    int a, b, c, n;
    printf("Enter first three elements with spaces: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Enter n: ");
    scanf("%d", &n);

    int term = threeFibo(a, b, c, n);
    printf("%dth term is %d\n", n, term);
    return 0;
}
