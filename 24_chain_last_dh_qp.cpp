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

//해시 테이블 초기화
void init_table(element* ht) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        ht[i].key[0] = NULL;
    }
}

//문자로 된 탐색키를 숫자로 변환
int transform(char* key) {
    int number = 0;
    while (*key)
        number += *key++;
    return number;
}
//제산 함수를 사용한 해싱 함수
int hash_function(char* key) {
    return transform(key) % TABLE_SIZE;
}
int hash_function2(char* key) {
    return (5 - (transform(key) % 5) % TABLE_SIZE);
}

//선형 조사법을 이용하여 테이블에 키를 삽입하고 테이블이 가득찬 경우에는 종료
void hash_lp_add(element item, element* ht) {
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색키가 중복 되었습니다\n");
            return;
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value) {
            fprintf(stderr, "테이블이 가득 찼습니다\n");
            return;
        }
    }
    ht[i] = item;
}
//이차 조사
void hash_qp_add(element item, element* ht) {
    int i, hash_value, inc = 0;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색키가 중복 되었습니다\n");
            return;
        }

        i = (hash_value + inc * inc) % TABLE_SIZE;
        inc = inc + 1;

        printf("이차조사 수행[%d]\n", i);
        if (i == hash_value) {
            fprintf(stderr, "테이블이 가득 찼습니다\n");
            return;
        }
    }
    ht[i] = item;
}
//이중 해싱
void hash_dh_add(element item, element* ht) {
    int i, hash_value, inc;
    hash_value = i = hash_function(item.key);
    inc = hash_function2(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색키가 중복 되었습니다\n");
            return;
        }
        i = (i + inc) % TABLE_SIZE;
        printf("이중해싱 수행[%d]\n", i);
        if (i == hash_value) {
            fprintf(stderr, "테이블이 가득 찼습니다\n");
            return;
        }
    }
    ht[i] = item;
}
//선형 탐색
void hash_lp_search(element item, element* ht) {
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색성공 : 위치 = %d\n", i);
            return;
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value) {
            fprintf(stderr, "찾는 값이 테이블에 없음\n");
            return;
        }
    }
    fprintf(stderr, "찾는 값이 테이블에 없음\n");
}
//이차 탐색
void hash_qp_search(element item, element* ht) {
    int i, hash_value, inc = 0;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색성공 : 위치 = %d\n", i);
            return;
        }

        i = (hash_value + inc * inc) % TABLE_SIZE;
        // 0, 1, 4, 9, 16, 25, 36
        inc = inc + 1;

        if (i == hash_value) {
            fprintf(stderr, "찾는 값이 테이블에 없음\n");
            return;
        }
    }
    fprintf(stderr, "찾는 값이 테이블에 없음\n");
}
//이중 탐색
void hash_dh_search(element item, element* ht) {
    int i, hash_value, inc;
    hash_value = i = hash_function(item.key);
    inc = hash_function2(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색성공 : 위치 = %d\n", i);
            return;
        }
        i = (i + inc) % TABLE_SIZE;

        if (i == hash_value) {
            fprintf(stderr, "찾는 값이 테이블에 없음\n");
            return;
        }
    }
    fprintf(stderr, "찾는 값이 테이블에 없음\n");
}


//해싱 테이블의 내용을 출력
void hash_lp_print(element* ht) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        printf("[%d]= %s\n", i, ht[i].key);
}

void main() {
    element tmp;
    int op;

    // 이중 해쉬
    while (1) {
        printf("이중 해싱] 원하는 연산을 입력(0=입력,1=탐색,2=종료): ");
        scanf_s("%d", &op);
        if (op == 2) break;
        printf("키값 입력 : ");
        scanf_s("%s", tmp.key, sizeof(tmp.key));

        if (op == 0)
            hash_dh_add(tmp, hash_table);
        else if (op == 1)
            hash_dh_search(tmp, hash_table);

        hash_lp_print(hash_table);
    }

    // 이차조사
    while (1) {
        printf("이차 조사] 원하는 연산을 입력(0=입력,1=탐색,2=종료): ");
        scanf_s("%d", &op);
        if (op == 2) break;
        printf("키값 입력 : ");
        scanf_s("%s", tmp.key, sizeof(tmp.key));

        if (op == 0)
            hash_qp_add(tmp, hash_table);
        else if (op == 1)
            hash_qp_search(tmp, hash_table);

        hash_lp_print(hash_table);
    }
}

