#pragma once

#include "searchable_bag.hpp"

class set
{
	searchable_bag *sb;
public:
	set() : sb(0) {}
	set(searchable_bag &b) : sb(&b) {}
	set(const set &o) : sb(o.sb) {}
	set &operator=(const set &o) { sb = o.sb; return *this; }
	~set() {}

	void insert(int v) { if (!sb->has(v)) sb->insert(v); }
	void insert(int *a, int n) { for (int i = 0; i < n; i++) insert(a[i]); }
	bool has(int v) const { return sb->has(v); }
	void print() const { sb->print(); }
	void clear() { sb->clear(); }
	searchable_bag &get_bag() { return *sb; }
	const searchable_bag &get_bag() const { return *sb; }
};
