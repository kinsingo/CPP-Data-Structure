#include <stdio.h>
#include <stdlib.h>

#define max(a, b)   (((a) > (b)) ? (a) : (b))

// 노드
typedef struct TreeNode
{
	int key;
	struct TreeNode* left, * right;
} TreeNode;

// 탐색
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (key == node->key)
	{
		return node;
	}
	else if (key < node->key)
	{
		return search(node->left, key);
	}
	else
	{
		return search(node->right, key);
	}
}

// 노드 삽입
// key를 이진 탐색 트리 root에 삽입한다.
// key가 이미 root안에 있으면 삽입하지 않는다.
void insert_node(TreeNode** root, int key)
{
	TreeNode* p, * t;    // p는 부모노드, t는 현재노드
	TreeNode* n;        // n은 새로운 노드

	t = *root;
	p = NULL;

	// 우선 탐색
	while (t != NULL)
	{
		if (key == t->key)
		{
			return;
		}

		p = t;

		if (key < t->key)
		{
			t = t->left;
		}
		else
		{
			t = t->right;
		}
	}

	// key가 트리 안에 없으므로 삽입 가능
	n = (TreeNode*)malloc(sizeof(TreeNode));

	if (n == NULL)
	{
		return;
	}

	// 데이터 복사
	n->key = key;
	n->left = n->right = NULL;

	// 부모 노드와 링크 연결
	if (p != NULL)
	{
		if (key < p->key)
		{
			p->left = n;
		}
		else
		{
			p->right = n;
		}
	}
	else
	{
		*root = n;
	}
}

// 노드 삭제
void delete_node(TreeNode** root, int key)
{
	TreeNode* p, * child, * succ, * succ_p, * t;

	// key를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;

	// key를 갖는 노드 t를 탐색
	while ((t != NULL) && (t->key != key))
	{
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}

	// 탐색이 종료된 시점에 t가 NULL이면 트리 안에 key가 없음
	if (t == NULL)
	{
		printf("key is not in the tree");
		return;
	}

	// 첫 번째 경우 : 단말노드인 경우
	if ((t->left == NULL) && (t->right == NULL))
	{
		if (p != NULL)
		{
			// 부모노드의 자식필드를 NULL로 만든다.
			if (p->left == t)
			{
				p->left = NULL;
			}
			else
			{
				p->right = NULL;
			}
		}
		else    // 만약 부모노드가 NULL이면 삭제되는 노드 = root
		{
			*root = NULL;
		}
	}
	// 두 번째 경우 : 하나의 자식만 가지는 경우
	else if ((t->left == NULL) || (t->right == NULL))
	{
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL)
		{
			if (p->left == t)
			{
				p->left = child;
			}
			else
			{
				p->right = child;
			}
		}
		else    // 만약 부모노드가 NULL이면 삭제되는 노드 = root
		{
			*root = child;
		}
	}
	// 세 번째 경우 : 두 개의 자식을 가지는 경우
	else
	{
		// 오른쪽 서브트리에서 후계자를 찾는다
		succ_p = t;
		succ = t->right;
		// 후계자를 찾아서 계속 왼쪽으로 이동한다
		while (succ->left != NULL)
		{
			succ_p = succ;
			succ = t->left;
		}
		// 후속자의 부모와 자식을 연결
		if (succ_p->left == succ)
		{
			succ_p->left = succ->right;
		}
		else
		{
			succ_p->right = succ->right;
		}
		// 후속자가 가진 키 값을 현재 노드에 복사
		t->key = succ->key;
		// 원래의 후속자 삭제
		t = succ;
	}
	free(t);
}

// 중위 순회
void inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);         // 왼쪽 서브트리 순회
		printf("%d -> ", root->key);  // 노드 방문
		inorder(root->right);            // 오른쪽 서브트리 순회
	}
}

// 전위 순회
void preorder(TreeNode* root)
{
	if (root)
	{
		printf("%d -> ", root->key);  // 노드 방문
		preorder(root->left);            // 왼쪽 서브트리 순회
		preorder(root->right);           // 오른쪽 서브트리 순회
	}
}

// 후위 순회
void postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);           // 왼쪽 서브트리 순회
		postorder(root->right);          // 오른쪽 서브트리 순회
		printf("%d -> ", root->key);  // 노드 방문
	}
}

// 노드 개수를 구하는 알고리즘
int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
	{
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}
	return count;
}

// 단말 노드 개수 구하기
int get_leaf_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
	{
		if (node->left == NULL && node->right == NULL)
		{
			return 1;
		}
		else
		{
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
		}
	}
	return count;
}

// 이진 트리에서 높이 구하기
int get_height(TreeNode* node)
{
	int height = 0;
	if (node != NULL)
	{
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	return height;
}

int main()
{
	int i;
	TreeNode* n1 = NULL;
	int data[] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = 8;
	insert_node(&n1, data[0]);
	// 배열 출력 
	printf("배열: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	for (i = 0; i < size; i++)
	{
		insert_node(&n1, data[i]);
		printf("\n 출력 : ");
		inorder(n1);
		printf("\n");
	}

	printf("\n 높이 : %d", get_height(n1));
	printf("\n 노드 수 : %d", get_node_count(n1));
	printf("\n 마지막 노드 수 : %d", get_leaf_count(n1));
	printf("\n");

	return 0;
}