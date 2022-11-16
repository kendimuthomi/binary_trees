#include "binary_trees.h"

/**
 * count_nodes - counts the number of nodes
 * @tree: pointer to the root of the tree
 * Return: number of node
 */
unsigned int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * complete - checks if tree is complete or not
 * @tree: pointer to the root of the tree
 * @index: index for the right and the left child
 * @num_nodes: number of nodes
 * Return: num_nodes
 */
int complete(const binary_tree_t *tree, int index, int num_nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= num_nodes)
		return (0);
	return (complete(tree->left, 2 * index + 1, num_nodes) &&
			complete(tree->right, 2 * index + 2, num_nodes));
}

/**
 * binary_tree_is_complete - checks if a tree is complete
 * @tree: pointer to the root node
 * Return: 1 if complete, 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int num_nodes = count_nodes(tree);
	int index = 0;

	if (tree == NULL)
		return (0);
	return (complete(tree, index, num_nodes));
}
