#include <stdio.h>

extern int add(int a, int b);
extern int sub(int a, int b);

int main() {
    printf("2 + 2 = %d\n", add(2, 2));
    printf("3 - 1 = %d\n", sub(3, 1));
}