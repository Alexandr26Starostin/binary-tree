#ifndef CONST_IN_BINARY_TREE
#define CONST_IN_BINARY_TREE

struct node_t 
{
	long data;
	node_t* left;
	node_t* right;
	node_t* parent;
};

enum tree_error_t
{
	NOT_ERROR           = 0,
	NOT_MEMORY_FOR_NODE = 1
};

#endif