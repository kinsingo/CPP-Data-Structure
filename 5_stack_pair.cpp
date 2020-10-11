#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;        //int�� ���� element�� �ڷ������� ����

typedef struct  stackNode {  //������ ��� ���� ����
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top;     //������ top ��带 �����ϱ� ���� ������ top ����

void push(element item) //������ ���� ����
{
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop()      //������ ���� �� ��ȯ ����
{
	element item;
	stackNode* temp = top;

	if (top == NULL) {   //���� ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {               //���� ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

void del()              //������ ���� ����
{
	stackNode* temp;
	if (top == NULL) {    //���� ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
	}
	else {              //���� ������ ���� ����Ʈ�� �ƴ� ���
		temp = top;
		top = top->link;
		free(temp);
	}
}

//���� peek
element peek()              //���Ḯ��Ʈ ������ top ���� �˻� ����
{
	element item;
	if (top == NULL) {
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		item = top->data;
		return item;
	}
}

void printStack()        //������ ���� ��� ����
{
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

int testPair(char* exp)        //������ ��ȣ�� �˻��ϴ� ����
{
	char symbol, open_pair;
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
		case '(':
		case '[':
		case '{':
			push(symbol); break;
		case ')':
		case ']':
		case '}':
			if (top == NULL) return 0;
			else {
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') ||
					(open_pair == '[' && symbol != ']') ||
					(open_pair == '{' && symbol != '}'))
					return 0;
				else break;
			}
		}
	}
	if (top == NULL) return 1;
	else return 0;
}


element evalPostfix(char* exp) {
	int opr1, opr2, value, i = 0;
	int length = strlen(exp);
	char symbol;
	top = NULL;
	for (i = 0; i < length; i++) {
		symbol = exp[i];
		if (symbol != '+' && symbol != '-'
			&& symbol != '*' && symbol != '/') {
			value = symbol - '0';
			printf("symbol: %d, '0': %d\n", symbol, '0');
			push(value);
		}
		else {
			opr2 = pop();
			opr1 = pop();
			switch (symbol) {
			case '+':
				push(opr1 + opr2); break;
			case '-':
				push(opr1 - opr2); break;
			case '*':
				push(opr1 * opr2); break;
			case '/':
				push(opr1 / opr2); break;
			}
		}
	}
	return pop();
}


void main(void)
{
	int result;
	char express[] = "35*62/-";
	printf("����ǥ��� : %s", express);

	result = evalPostfix(express);
	printf("\n\n ������ => %d", result);

	/*char express[] = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", express);
	if (testPair(express) == 1)
		printf("\n\n ������ ��ȣ�� �°� ���Ǿ����ϴ�!");
	else
		printf("\n\n ������ ��ȣ�� Ʋ�Ƚ��ϴ�!");*/
}
