#include <stdio.h>
int size, i = 0;
#define parent(x) (x-1)/2
void heap(int* data, int num) {
	for (int i = 1; i < num; i++) {
		int child = i;
		while (child > 0) {
			int root = parent(child);
			if (data[root] < data[child]) {
				int temp = data[root];
				data[root] = data[child];
				data[child] = temp;
			}
			child = root;
		}
	}
}
int main()
{
	int num = 10;
	int data[] = { 69, 10, 30, 2, 16, 8, 31, 22, 100, 50 };
	//���簪 ��� 
	printf("���� �迭: ");
	for (int i = 0; i < num; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	heap(data, num); // ���� �����. 

	for (int i = num - 1; i >= 0; i--) {
		// ����ū ����(root)�� �� ������ ���ҿ� ���� 
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		// �Ǹ���������(����ū����)�� �����ϰ� �ٽ� ���� �����. 
		heap(data, i);
	}

	// ��� ��� 
	printf("��� �迭: ");
	for (int i = 0; i < num; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	return 0;
}
