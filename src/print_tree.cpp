#include <stdio.h>
#include <assert.h>

#include "const_in_binary_tree.h"
#include "print_tree.h"

tree_error_t print_inorder_tree (node_t* ptr_node)
{
	assert (ptr_node);

	printf ("(");

	if ((ptr_node -> left) != NULL)
	{
		print_inorder_tree (ptr_node -> left);
	}

	printf ("%ld", ptr_node -> data);

	if ((ptr_node -> right) != NULL)
	{
		print_inorder_tree (ptr_node -> right);
	}

	printf (")");
	
	return NOT_ERROR;
}