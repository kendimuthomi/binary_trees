#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *father, *granny;
	if (node == NULL)
		return (NULL);
	father = node->parent;
	if (father == NULL)
		return (NULL);
	granny = father->parent;
	if (granny == NULL)
		return (NULL);
	if (granny->left == father)
		return (granny->right);
	return (granny->right);
}
