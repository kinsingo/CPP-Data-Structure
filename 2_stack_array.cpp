#include <stdio.h>

#define STACK_SIZE 100

typedef int element;
element stack[STACK_SIZE];

int top = -1;


void push(element item) {
    // stack이 full 인지 확인하는 코드

    top = top + 1;
    stack[top] = item;
}


element pop() {
    // 삭제 하는 것
    // stack이 empty 인지 확인하는 코드
    //  top == -1
    int rtn = stack[top];
    top = top - 1;    
    return rtn;
}

void del() {
    // empty 인지 확인하는 코드
    top = top - 1;
}

element peek() {
    // empty 인지 확인하는 코드
    // 삭제 하지 않는 것
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