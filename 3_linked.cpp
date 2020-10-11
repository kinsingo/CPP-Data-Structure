#include <stdlib.h>
#include <stdio.h>

typedef int element;


typedef struct Node {
    element data;
	struct  Node *link;
} Node;


void main() {
    struct Node* top;

    Node* p = (Node*)malloc(sizeof(Node));

    p->data = 1;
    p->link = NULL;

    top = p;

    printf("%d\n", top->data);


    p = (Node*)malloc(sizeof(Node));
    p->data = 2;
    p->link = top;

    top = p;

    printf("%d\n", top->data);

    // ctrl + k + c : 블럭 주석
    // ctrl + k + u : 블럭 주석 해제
    //Node* p = (Node*)malloc(sizeof(Node));
    //p->data = 1;

}