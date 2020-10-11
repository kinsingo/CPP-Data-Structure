#include <stdio.h>

int Find_Max(int a[], int n) {
    int i, tmp;
    tmp = a[0];
    for (i = 0; i < n; i++) {
        if (tmp < a[i]) {
            tmp = a[i];
        }
    }

    return tmp;
}

void main() {
    int ary[] = { 10, 20, 30, 40 ,25, 100, 34 };

    printf("�ִ밪 : %d \n", Find_Max(ary, 7));
}