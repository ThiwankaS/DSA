#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int data;
	struct s_node *left;
	struct s_node *right;

} t_node;

t_node *create_node(int value)
{
	t_node *node = malloc(sizeof(t_node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}


void print_tree_depth_first(t_node *root)
{
	if(root)
		printf("%d, ", root->data);
	if(root->left)
		print_tree_depth_first(root->left);
	if(root->right)
		print_tree_depth_first(root->right);
}

int main(void)
{
	t_node *root = create_node(10);
	root->left = create_node(20);
	root->right = create_node(30);
	root->left->left = create_node(40);
	root->left->right = create_node(50);
	root->right->left = create_node(60);
	root->right->right = create_node(70);
	print_tree_depth_first(root);
	printf("\n");
	return (0);
}
