#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the
 *  tree to measure the height
 *  Return: size of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (tree == NULL)
		return (0);
	l_height += 1 + binary_tree_height(tree->left);
	r_height += 1 + binary_tree_height(tree->right);
	if (l_height > r_height)
		return (l_height);
	else
		return (r_height);
}

/**
 * print_level - prints the nodes by level
 * @func: pointer to a function
 * @level: the level
 * @node: pointer to the node
 */
void print_level(binary_tree_t *node, void (*func)(int), int level)
{
	if (node == NULL || func == NULL)
		return;
	if (level == 1)
		func(node->n);
	else if (level > 1)
	{
		print_level(node->left, func, level - 1);
		print_level(node->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary
 * tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h = 0, i;
	binary_tree_t *tree2 = (binary_tree_t *)tree;

	if (tree == NULL || func == NULL)
		return;
	h = binary_tree_height(tree);
	for (i = 0; i <= h + 1; i++)
		print_level(tree2, func, i);
}
