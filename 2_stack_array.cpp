#include <stdio.h>

#define STACK_SIZE 100

typedef int element;
element stack[STACK_SIZE];

int top = -1;


void push(element item) {
    // stack�� full ���� Ȯ���ϴ� �ڵ�

    top = top + 1;
    stack[top] = item;
}


element pop() {
    // ���� �ϴ� ��
    // stack�� empty ���� Ȯ���ϴ� �ڵ�
    //  top == -1
    int rtn = stack[top];
    top = top - 1;    
    return rtn;
}

void del() {
    // empty ���� Ȯ���ϴ� �ڵ�
    top = top - 1;
}

element peek() {
    // empty ���� Ȯ���ϴ� �ڵ�
    // ���� ���� �ʴ� ��
    return stack[top];
}


void main() {
    push(1);
    push(2);
    push(3);

    printf("peek %d\n", peek());

    printf("pop %d\n", pop());
    printf("pop %d\n", pop());
    printf("pop %d\n", pop());
}