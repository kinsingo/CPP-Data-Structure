#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 10
#define TABLE_SIZE 7

#define empty(e) (strlen(e.key)==0)
#define equal(e1,e2) (!strcmp(e1.key,e2.key))

typedef struct {
    char key[KEY_SIZE];
}element;

element hash_table[TABLE_SIZE];

//�ؽ� ���̺� �ʱ�ȭ
void init_table(element* ht) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        ht[i].key[0] = NULL;
    }
}

//���ڷ� �� Ž��Ű�� ���ڷ� ��ȯ
int transform(char* key) {
    int number = 0;
    while (*key)
        number += *key++;
    return number;
}
//���� �Լ��� ����� �ؽ� �Լ�
int hash_function(char* key) {
    return transform(key) % TABLE_SIZE;
}
int hash_function2(char* key) {
    return (5 - (transform(key) % 5) % TABLE_SIZE);
}

//���� ������� �̿��Ͽ� ���̺� Ű�� �����ϰ� ���̺��� ������ ��쿡�� ����
void hash_lp_add(element item, element* ht) {
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "Ž��Ű�� �ߺ� �Ǿ����ϴ�\n");
            return;
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value) {
            fprintf(stderr, "���̺��� ���� á���ϴ�\n");
            return;
        }
    }
    ht[i] = item;
}
//���� ����
void hash_qp_add(element item, element* ht) {
    int i, hash_value, inc = 0;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "Ž��Ű�� �ߺ� �Ǿ����ϴ�\n");
            return;
        }

        i = (hash_value + inc * inc) % TABLE_SIZE;
        inc = inc + 1;

        printf("�������� ����[%d]\n", i);
        if (i == hash_value) {
            fprintf(stderr, "���̺��� ���� á���ϴ�\n");
            return;
        }
    }
    ht[i] = item;
}
//���� �ؽ�
void hash_dh_add(element item, element* ht) {
    int i, hash_value, inc;
    hash_value = i = hash_function(item.key);
    inc = hash_function2(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "Ž��Ű�� �ߺ� �Ǿ����ϴ�\n");
            return;
        }
        i = (i + inc) % TABLE_SIZE;
        printf("�����ؽ� ����[%d]\n", i);
        if (i == hash_value) {
            fprintf(stderr, "���̺��� ���� á���ϴ�\n");
            return;
        }
    }
    ht[i] = item;
}
//���� Ž��
void hash_lp_search(element item, element* ht) {
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "Ž������ : ��ġ = %d\n", i);
            return;
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value) {
            fprintf(stderr, "ã�� ���� ���̺� ����\n");
            return;
        }
    }
    fprintf(stderr, "ã�� ���� ���̺� ����\n");
}
//���� Ž��
void hash_qp_search(element item, element* ht) {
    int i, hash_value, inc = 0;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "Ž������ : ��ġ = %d\n", i);
            return;
        }

        i = (hash_value + inc * inc) % TABLE_SIZE;
        // 0, 1, 4, 9, 16, 25, 36
        inc = inc + 1;

        if (i == hash_value) {
            fprintf(stderr, "ã�� ���� ���̺� ����\n");
            return;
        }
    }
    fprintf(stderr, "ã�� ���� ���̺� ����\n");
}
//���� Ž��
void hash_dh_search(element item, element* ht) {
    int i, hash_value, inc;
    hash_value = i = hash_function(item.key);
    inc = hash_function2(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "Ž������ : ��ġ = %d\n", i);
            return;
        }
        i = (i + inc) % TABLE_SIZE;

        if (i == hash_value) {
            fprintf(stderr, "ã�� ���� ���̺� ����\n");
            return;
        }
    }
    fprintf(stderr, "ã�� ���� ���̺� ����\n");
}


//�ؽ� ���̺��� ������ ���
void hash_lp_print(element* ht) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        printf("[%d]= %s\n", i, ht[i].key);
}

void main() {
    element tmp;
    int op;

    // ���� �ؽ�
    while (1) {
        printf("���� �ؽ�] ���ϴ� ������ �Է�(0=�Է�,1=Ž��,2=����): ");
        scanf_s("%d", &op);
        if (op == 2) break;
        printf("Ű�� �Է� : ");
        scanf_s("%s", tmp.key, sizeof(tmp.key));

        if (op == 0)
            hash_dh_add(tmp, hash_table);
        else if (op == 1)
            hash_dh_search(tmp, hash_table);

        hash_lp_print(hash_table);
    }

    // ��������
    while (1) {
        printf("���� ����] ���ϴ� ������ �Է�(0=�Է�,1=Ž��,2=����): ");
        scanf_s("%d", &op);
        if (op == 2) break;
        printf("Ű�� �Է� : ");
        scanf_s("%s", tmp.key, sizeof(tmp.key));

        if (op == 0)
            hash_qp_add(tmp, hash_table);
        else if (op == 1)
            hash_qp_search(tmp, hash_table);

        hash_lp_print(hash_table);
    }
}

