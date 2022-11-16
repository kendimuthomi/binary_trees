#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);
		if (left == 0 || right == 0)
			return (0);
		return (1);
	}
	return (0);
}
/**
 *  * binary_tree_height - measures the height of a binary tree
 *   * @tree: pointer to the root node of the
 *    *  tree to measure the height
 *     *  Return: size of tree
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
	return (r_height);
}

/**
 *  * binary_tree_balance - measures the balance factor of a binary tree
 *   * @tree: pointer to the root node of the
 *    *  tree to measure the balance factor
 *     * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (left_height - right_height);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if perfect 1 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((binary_tree_is_full(tree) == 1) &&
			(binary_tree_balance(tree) == 0))
		return (1);
	return (0);
}
