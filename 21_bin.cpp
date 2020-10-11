#include <stdio.h>

// ���� Ž�� �˰��� �ݺ��� ���� // ã�� ���ڰ� ������ ã�� ������ �ε��� ���� ������ -1 ����
int BSearch(int ar[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid = 0;

	// while(first < last)�̸� ������ �ϳ���
	// �˻����� �ʰ� ����
	while (first <= last) {
		mid = (first + last) / 2;
		if (ar[mid] == target) {
			return mid;
		}
		else {
			if (ar[mid] > target)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;
}

int interpol_search(int list[], int n, int key)
{
	int low, high, j;

	low = 0;
	high = n - 1;
	while ((list[high] >= key) && (key > list[low])) {
		j = ((float)(key - list[low]) / (list[high] - list[low])
			* (high - low)) + low;
		if (key > list[j]) low = j + 1;
		else if (key < list[j]) high = j - 1;
		else low = j;

		printf("���� ����\n");
	}
	if (list[low] == key) return(low);  // Ž������
	else return -1;  // Ž������
}

// ���� Ž�� �˰��� ��� ����
int BSearchRecur(int ar[], int first, int last, int target) {
	int mid = (first + last) / 2;
	if (first > last)
		return -1;
	else {
		if (ar[mid] == target)
			return mid;
		else {
			if (ar[mid] > target) {
				last = mid - 1;
				BSearchRecur(ar, first, last, target);
			}
			else {
				first = mid + 1;
				BSearchRecur(ar, first, last, target);
			}
		}
	}
}

void main()
{
	int array[] = { 2, 8, 10, 16, 22, 30, 31, 50, 69, 100 };
	int n = 10;
	int idx;

	printf("\n\t<< ���� Ʈ�� �˻� >>\n");

	idx = BSearch(array, sizeof(array) / sizeof(int), 16);
	if (idx == -1) {
		printf("Fail\n");
	}
	else {
		printf("Target Index : %d\n", idx);
	}

	printf("\n\t<< ���� Ʈ�� ��� �˻� >>\n");
	idx = BSearchRecur(array, 0, sizeof(array) / sizeof(int) - 1, 69);
	if (idx == -1) {
		printf("Fail\n");
	}
	else {
		printf("Target Index : %d\n", idx);
	}

	printf("\n\t<< ���� Ʈ�� ���� �˻� >>\n");
	idx = interpol_search(array, sizeof(array) / sizeof(int), 16);
	if (idx == -1) {
		printf("Fail\n");
	}
	else {
		printf("Target Index : %d\n", idx);
	}
}