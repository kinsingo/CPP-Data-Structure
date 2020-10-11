#include <stdio.h>

void print_element(int ary[], int size, const char* msg)
{
    printf("\n%s", msg);

    for (int n = 0; n < size; n++) {
        printf("%d\t", ary[n]);
    }
    printf("\n", msg);
}

void intervalSort(int a[], int begin, int end, int interval)
{
    int i, j, item;
    for (i = begin + interval; i <= end; i = i + interval) {
        item = a[i];
        for (j = i - interval; j >= begin && item < a[j]; j = j - interval) {
            a[j + interval] = a[j];
        }
        a[j + interval] = item;
    }
}

void shellSort(int a[], int size)
{
    int i, t, interval;
    interval = size / 2;

    while (interval >= 1) {
        for (i = 0; i < interval; i++) {
            intervalSort(a, i, size - 1, interval);
        }
        interval = interval / 2;
    }
}

void quickSort(int ary[], int begin, int end) {
    if (begin >= end) {
        return;
    }
    int pivot = ary[(begin + end) / 2];
    int left = begin;
    int right = end;
    int tmp = 0;
    while (left <= right) {
        while (ary[left] < pivot) {
            left++;
        }
        while (ary[right] > pivot) {
            right--;
        }
        if (left <= right) {
            tmp = ary[left];
            ary[left] = ary[right];
            ary[right] = tmp;
            left++;
            right--;
        }
    }
    quickSort(ary, begin, right);
    quickSort(ary, left, end);
}

void insertionSort(int ary[], int size) {
    int temp = 0;
    int j = 0;
    for (int i = 1; i < size; i++) {
        temp = ary[i];
        j = i;

        while ((j > 0) && (ary[j - 1] > temp)) {
            // temp 보다 크다면, 계속 자리교환이 발생함
            ary[j] = ary[j - 1];
            j = j - 1;
        }
        ary[j] = temp;

        print_element(ary, size, "중간 확인:\n");
    }
}

void bubbleSort(int ary[], int size) {
    int temp = 0;
    for (int i = 0; i < size - 1; i++) {

        for (int j = 1; j < size; j++) {
            if (ary[j - 1] > ary[j]) {
                temp = ary[j - 1];
                ary[j - 1] = ary[j];
                ary[j] = temp;
            }
        }
        print_element(ary, size, "중간 확인:\n");
    }
}

void selectionSort(int ary[], int size) {
    int n_min_idx = 0;
    int temp = 0;
    for (int i = 0; i < size - 1; i++) {
        n_min_idx = i;

        for (int j = i + 1; j < size; j++) {
            if (ary[j] < ary[n_min_idx]) {
                n_min_idx = j;
            }
        }
        temp = ary[i];
        ary[i] = ary[n_min_idx];
        ary[n_min_idx] = temp;
        print_element(ary, size, "중간 확인:\n");
    }
}

int main() {
    int size = 10;
    int list[10];
    for (int i = 0; i < 10; i++) {
        list[i] = 10 - i;
    }

    printf("정렬 종류 선택: ");

    int n_type = 0;

    scanf_s("%d", &n_type, sizeof(n_type));


    print_element(list, size, "입력값:\n");
    printf("\n\n");

    switch (n_type)
    {
    case 0:
        printf("\n\n<<<<<< 선택정렬 >>>>>>> \n\n");
        selectionSort(list, size);
        break;
    case 1:
        printf("\n\n<<<<<< 버블정렬 >>>>>>> \n\n");
        bubbleSort(list, size);
        break;
    case 2:
        printf("\n\n<<<<<< 삽입정렬 >>>>>>> \n\n");
        insertionSort(list, size);
        break;
    case 3:
        printf("\n\n<<<<<< 퀵정렬 >>>>>>> \n\n");
        quickSort(list, 0, size -1);
        break;
    case 4:
        printf("\n\n<<<<<< 쉘정렬 >>>>>>> \n\n");
        shellSort(list, size);
        break;
    }


    print_element(list, size, "\n\n출력값:\n");
}