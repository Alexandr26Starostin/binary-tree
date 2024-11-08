#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "const_in_binary_tree.h"
#include "new_node.h"

tree_error_t creat_new_node (node_t** ptr_ptr_node, long value, int line, const char* file)
{
	assert (file);   //ptr_ptr_node == NULL

	*ptr_ptr_node = (node_t*) calloc (1, sizeof (node_t));
	if (ptr_ptr_node == NULL)
	{
		printf ("Error in %s:%d\nName memory: NOT_MEMORY_FOR_NODE\nFor value == %ld calloc return NULL in file: creat_new_node.cpp\n", file, line, value);
		return NOT_MEMORY_FOR_NODE;
	}

	(*ptr_ptr_node) -> data   = value;
	(*ptr_ptr_node) -> right  = NULL;
	(*ptr_ptr_node) -> left   = NULL;
	(*ptr_ptr_node) -> parent = NULL;

	return NOT_ERROR;
}

tree_error_t attach_node (long value, node_t* ptr_first_parent, int line, const char* file)
{
	assert (ptr_first_parent);
	assert (file);

	node_t* ptr_new_node = NULL;

	tree_error_t status = creat_new_node (&ptr_new_node, value, line, file);
	if (status) {return status;}

	find_position_node (ptr_new_node, ptr_first_parent);

	return status;
}

tree_error_t find_position_node (node_t* ptr_new_node, node_t* ptr_parent)
{
	assert (ptr_new_node);
	assert (ptr_parent);

	if ((ptr_new_node -> data) <= (ptr_parent -> data))
	{
		if (ptr_parent -> left == NULL)
		{
			ptr_parent   -> left   = ptr_new_node;
			ptr_new_node -> parent = ptr_parent;
			return NOT_ERROR;
		}
		else 
		{
			ptr_parent = ptr_parent -> left;
			find_position_node (ptr_new_node, ptr_parent);
		}
	}
	else 
	{
		if (ptr_parent -> right == NULL)
		{
			ptr_parent   -> right  = ptr_new_node;
			ptr_new_node -> parent = ptr_parent;
			return NOT_ERROR;
		}
		else
		{
			ptr_parent = ptr_parent -> right;
			find_position_node (ptr_new_node, ptr_parent);
		}
	}

	return NOT_ERROR;
}

