#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct n {

	int data;
	n* left;
	n* right;

};

typedef n node;

node* ekle(node* tree, int x)
{
	if (tree == NULL)
	{
		node* root = (node*)malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->data = x;
		return root;
	}

	if (tree->data < x)
	{
		tree->right = ekle(tree->right, x);
		return tree;


	}

	tree->left = ekle(tree->left, x);
	return tree;

}

void preorder(node* tree)
{

	if (tree != NULL)
	{
		printf("%d ", tree->data);
		preorder(tree->left);
		preorder(tree->right);

	}

}

void inorder(node* tree)
{
	if (tree != NULL)
	{
		inorder(tree->left);
		printf("%d ", tree->data);
		inorder(tree->right);
	}
}


void postorder(node* tree)
{

	if (tree != NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d ", tree->data);
	}
}
int main()

{
	node* tree = NULL;
	int i, x;
	srand(time(NULL));
	printf("The number being placed in the three are: ");
	for (i = 0; i < 10; i++)
	{
		tree = ekle(tree, x = 1 + rand() % 25);
		printf("%d ", x);
	}

	printf("\n");
	printf("The preorder traversal is : ");
	preorder(tree);
	printf("\n");
	printf("The inorder traversal is: ");
	inorder(tree);
	printf("\n");


	printf("The postorder traversal is: ");
	postorder(tree);
	printf("\n");

}