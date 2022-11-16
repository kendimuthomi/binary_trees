#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	tmp = tree->left;
	tree->left = tmp->right;
	if (tmp->right != NULL)
		tmp->right->parent = tree;
	tmp->right = tree;
	tmp->parent = tree->parent;
	tree->parent = tmp;
	return (tmp);
}
