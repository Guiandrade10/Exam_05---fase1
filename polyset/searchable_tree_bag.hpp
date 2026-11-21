#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
public:
	searchable_tree_bag() {}
	searchable_tree_bag(const searchable_tree_bag &o) : tree_bag(o) {}
	searchable_tree_bag &operator=(const searchable_tree_bag &o) { tree_bag::operator=(o); return *this; }
	~searchable_tree_bag() {}

	bool has(int v) const
	{
		node *n = tree;
		while (n && n->value != v)
			n = v < n->value ? n->l : n->r;
		return n != 0;
	}
};
