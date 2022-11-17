#include "binary_trees.h"

/**
 * max_value - checks the maximum value
 * @node: node to check value
 * Return: the maximum value
 */
int max_value(binary_tree_t *node, int value)
{
	int left_max = 0, right_max = 0;

	if (node == NULL)
		return (1);
	left_max = max_value(node->left, value);
	right_max = max_value(node->right, value);
	if (left_max == right_max && left_max == 1)
		return (1);
	if (value <= node->n)
		return (0);
	return (1);
}

/**
 * min_value - checks the minimum value
 * @node: pointer to node whose value will be checked
 * Return: the minimum value
 */
int min_value(binary_tree_t *node, int value)
{
	int left_min, right_min;

	if (node == NULL)
		return (1);
	left_min = min_value(node->left, value);
	right_min = min_value(node->right, value);
	if (left_min == right_min && left_min == 1)
		return (1);
	if (node->n <= value)
		return (0);
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree
 * is a binary search tree
 * @tree: pointer to the root node for the binary tree
 * Return: 1 if bst 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int value = 0, left = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		value = max_value(tree->left, tree->n);
		if (value == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		value = min_value(tree->right, tree->n);
		if (value == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
