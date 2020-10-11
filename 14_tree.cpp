#include <stdio.h>
#include <stdlib.h>

#define max(a, b)   (((a) > (b)) ? (a) : (b))

// ���
typedef struct TreeNode
{
	int key;
	struct TreeNode* left, * right;
} TreeNode;

// Ž��
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

// ��� ����
// key�� ���� Ž�� Ʈ�� root�� �����Ѵ�.
// key�� �̹� root�ȿ� ������ �������� �ʴ´�.
void insert_node(TreeNode** root, int key)
{
	TreeNode* p, * t;    // p�� �θ���, t�� ������
	TreeNode* n;        // n�� ���ο� ���

	t = *root;
	p = NULL;

	// �켱 Ž��
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

	// key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode*)malloc(sizeof(TreeNode));

	if (n == NULL)
	{
		return;
	}

	// ������ ����
	n->key = key;
	n->left = n->right = NULL;

	// �θ� ���� ��ũ ����
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

// ��� ����
void delete_node(TreeNode** root, int key)
{
	TreeNode* p, * child, * succ, * succ_p, * t;

	// key�� ���� ��� t�� Ž��, p�� t�� �θ���
	p = NULL;
	t = *root;

	// key�� ���� ��� t�� Ž��
	while ((t != NULL) && (t->key != key))
	{
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}

	// Ž���� ����� ������ t�� NULL�̸� Ʈ�� �ȿ� key�� ����
	if (t == NULL)
	{
		printf("key is not in the tree");
		return;
	}

	// ù ��° ��� : �ܸ������ ���
	if ((t->left == NULL) && (t->right == NULL))
	{
		if (p != NULL)
		{
			// �θ����� �ڽ��ʵ带 NULL�� �����.
			if (p->left == t)
			{
				p->left = NULL;
			}
			else
			{
				p->right = NULL;
			}
		}
		else    // ���� �θ��尡 NULL�̸� �����Ǵ� ��� = root
		{
			*root = NULL;
		}
	}
	// �� ��° ��� : �ϳ��� �ڽĸ� ������ ���
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
		else    // ���� �θ��尡 NULL�̸� �����Ǵ� ��� = root
		{
			*root = child;
		}
	}
	// �� ��° ��� : �� ���� �ڽ��� ������ ���
	else
	{
		// ������ ����Ʈ������ �İ��ڸ� ã�´�
		succ_p = t;
		succ = t->right;
		// �İ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�
		while (succ->left != NULL)
		{
			succ_p = succ;
			succ = t->left;
		}
		// �ļ����� �θ�� �ڽ��� ����
		if (succ_p->left == succ)
		{
			succ_p->left = succ->right;
		}
		else
		{
			succ_p->right = succ->right;
		}
		// �ļ��ڰ� ���� Ű ���� ���� ��忡 ����
		t->key = succ->key;
		// ������ �ļ��� ����
		t = succ;
	}
	free(t);
}

// ���� ��ȸ
void inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);         // ���� ����Ʈ�� ��ȸ
		printf("%d -> ", root->key);  // ��� �湮
		inorder(root->right);            // ������ ����Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
void preorder(TreeNode* root)
{
	if (root)
	{
		printf("%d -> ", root->key);  // ��� �湮
		preorder(root->left);            // ���� ����Ʈ�� ��ȸ
		preorder(root->right);           // ������ ����Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
void postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);           // ���� ����Ʈ�� ��ȸ
		postorder(root->right);          // ������ ����Ʈ�� ��ȸ
		printf("%d -> ", root->key);  // ��� �湮
	}
}

// ��� ������ ���ϴ� �˰���
int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
	{
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}
	return count;
}

// �ܸ� ��� ���� ���ϱ�
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

// ���� Ʈ������ ���� ���ϱ�
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
	// �迭 ��� 
	printf("�迭: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	for (i = 0; i < size; i++)
	{
		insert_node(&n1, data[i]);
		printf("\n ��� : ");
		inorder(n1);
		printf("\n");
	}

	printf("\n ���� : %d", get_height(n1));
	printf("\n ��� �� : %d", get_node_count(n1));
	printf("\n ������ ��� �� : %d", get_leaf_count(n1));
	printf("\n");

	return 0;
}