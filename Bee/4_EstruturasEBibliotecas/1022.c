#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int abs(int a) {
    if (a < 0)
        a *= -1;
    return a;
}

char *operation_result(char op, int n1, int d1, int n2, int d2) {
    int numerator = 0, denominator = 0;
    switch (op) {
        case '+':
            numerator = n1 * d2 + n2 * d1;
            denominator = d1 * d2;
            break;
        case '-':
            numerator = n1 * d2 - n2 * d1;
            denominator = d1 * d2;
            break;
        case '*':
            numerator = n1 * n2;
            denominator = d1 * d2;
            break;
        case '/':
            numerator = n1 * d2;
            denominator = n2 * d1;
            break;
        default:
            break;
    }
    char *result = (char *)malloc(3000 * sizeof(char));
    sprintf(result, "%d/%d", numerator, denominator);
    return result;
}

char *simplify(char *f) {
    int numerator, denominator, i;
    sscanf(f, "%d/%d", &numerator, &denominator);

    int a = abs(numerator);
    int b = abs(denominator);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;

    numerator /= gcd;
    denominator /= gcd;

    char *result = (char *)malloc(3000 * sizeof(char));
    sprintf(result, "%d/%d", numerator, denominator);
    return result;
}

int main() {
    int tests, i, aux;
    int numerator1, denominator1, numerator2, denominator2;
    char operation;
    char *result;
    char *result_simplify;
    scanf("%d", &tests);
    while ((aux = getchar()) != '\n' && aux != EOF);

    for (i = 0; i < tests; i++) {
        scanf("%d / %d %c %d / %d", &numerator1, &denominator1, &operation, &numerator2, &denominator2);
        while ((aux = getchar()) != '\n' && aux != EOF);

        result = operation_result(operation, numerator1, denominator1, numerator2, denominator2);
        result_simplify = simplify(result);
        printf("%s = %s\n", result, result_simplify);

        free(result);
        free(result_simplify); 
    }
    return 0;
}
