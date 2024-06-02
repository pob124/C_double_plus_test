#include <iostream>

using namespace std;

typedef struct _TreeNode {
	int key;
	struct _TreeNode* left, * right;
} TreeNode;


TreeNode* search(TreeNode* node, int  key)
{
	if (node == NULL)
		return NULL;
	if (key == node->key)
		return node;
	else if (key < node->key)
		return  search(node->left, key);
	else
		return  search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);	// ���ʼ���Ʈ��
		printf("%d ", root->key); 	// ��� �湮
		inorder(root->right);	// �����ʼ���Ʈ��
	}
}

void decrement(TreeNode* p) {
	if (p != NULL) {
		decrement(p->left);
		p->key = p->key - 1;
		decrement(p->right);
	}
}


TreeNode* max_value_node(TreeNode* node)
{
	TreeNode* current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current-> right != NULL)
		current = current->right;

	return current;
}

TreeNode* delete_node(TreeNode* root, int key) { // key ��� ���� �� ��Ʈ ��ȯ
	if (root == NULL) return root;
	if (key < root->key) 			// Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� ����
		root->left = delete_node(root->left, key);
	else if (key > root->key) 		// Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� ����
		root->right = delete_node(root->right, key);
	else {				// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
		if (root->left == NULL) {	// ù ��°�� �� ��° ���
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {	// �� ��° ���
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = max_value_node(root->left); 		// �� ��° ���
		root->key = temp->key; 				// ���� Ű ����
		root->left = delete_node(root->left, temp->key); 	// ���� ��� ����
	}
	return root;
}

int main(void)
{
	TreeNode* root = NULL;
	root = insert_node(root, 11);
	root = insert_node(root, 3);
	root = insert_node(root, 4);
	root = insert_node(root, 1);
	root = insert_node(root, 56);
	root = insert_node(root, 5);
	root = insert_node(root, 6);
	root = insert_node(root, 2);
	root = insert_node(root, 98);
	root = insert_node(root, 32);
	root = insert_node(root, 23);
	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n");
	decrement(root);
	printf("1�� ������ �� ���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
		inorder(root);
		printf("\n");
		printf("\n");
	printf("��� ������ ���� ��ȸ ��� (���� 5 ) \n");
	delete_node(root, 5);
	inorder(root);
	printf("\n");
	printf("\n");
	printf("��� ������ ���� ��ȸ ��� (���� 55 ) \n");
	delete_node(root, 55);
	printf("\n");
	inorder(root);
	return 0;
}
