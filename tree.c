#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
	int data;
	struct s_node *left;
	struct s_node *right;

} t_node;

t_node *create_node(int value) {
	t_node *node = malloc(sizeof(t_node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * Prints the binary tree nodes using pre-order traversal (root → left → right).
 *Visualization Example:

        10
     /      \
    20      30
   /  \    /  \
  40   50 60  70

 *Output: 10, 20, 40, 50, 30, 60, 70
 */

void print_tree_depth_first(t_node *root) {
	if(root)
		printf("%d, ", root->data);
	if(root->left)
		print_tree_depth_first(root->left);
	if(root->right)
		print_tree_depth_first(root->right);
}

/**
 * Calculate the height of the tree
*/
int get_tree_height(t_node *root) {
	if (root == NULL)
		return (0);

	int left_height = get_tree_height(root->left);
	int right_height = get_tree_height(root->right);

	return((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * helper funtion to print a given tree node level of a tree
*/
void print_tree_level(t_node *root, int level) {
	if(!root)
		return;
	if(level == 1)
		printf("%d, ", root->data);
	else if(level > 1) {
		print_tree_level(root->left, level - 1);
		print_tree_level(root->right, level - 1);
	}
}

/**
 * Prints the binary tree nodes using pre-order traversal (level 1 → level 2 → level 3).
 *Visualization Example:

        10
     /      \
    20      30
   /  \    /  \
  40   50 60  70

 *Output: 10, 20, 30, 40, 50, 60, 70
 */
void print_tree_breadth_first(t_node *root) {
	int height = get_tree_height(root);
	for(int i = 1; i <= height; i++)
		print_tree_level(root, i);
}

/**
 * Deallocating memory and free up to prevent memomry leaks
*/
void exit_tree(t_node *node) {
	if(node->left)
		exit_tree(node->left);
	if(node->right)
		exit_tree(node->right);
	if(node)
		free(node);
}

int main(void) {
	t_node *root = create_node(10);
	root->left = create_node(20);
	root->right = create_node(30);
	root->left->left = create_node(40);
	root->left->right = create_node(50);
	root->right->left = create_node(60);
	root->right->right = create_node(70);
	printf("depth first approach: \n");
	print_tree_depth_first(root);
	printf("\n");
	printf("breadth first approach: \n");
	print_tree_breadth_first(root);
	printf("\n");
	exit_tree(root);
	return (0);
}
