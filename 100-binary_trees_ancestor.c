#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common
 *   ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *l, *r;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t*)first);
	l = first->parent;
	r = second->parent;

	if (l == NULL || first == r || (!l->parent && r))
		return (binary_trees_ancestor(first, r));
	else if (r == NULL || l == second || (!r->parent && l))
		return (binary_trees_ancestor(l, second));
	return (binary_trees_ancestor(l, r));
}
