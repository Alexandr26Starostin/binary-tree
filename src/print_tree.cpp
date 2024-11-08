#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "const_in_binary_tree.h"
#include "print_tree.h"

static tree_error_t print_edge (node_t* ptr_node, FILE* dump_file);

//------------------------------------------------------------------

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

tree_error_t dump_inorder_tree (node_t* ptr_node)
{
	assert (ptr_node);

	FILE* dump_file = fopen ("tree.dot", "w");
	if (dump_file == NULL) {printf ("Not find tree.dot\n"); return NOT_FIND_TREE_DOT;}

	fprintf (dump_file, "digraph\n{\n\trankdir = TB\n\tnode[fontsize=9]\n\tedge[color=\"green\",fontsize=12]\n\n\t");

	print_edge (ptr_node, dump_file);

	fprintf (dump_file, "\n}");

	getchar ();
	fclose (dump_file);

	system ("dot tree.dot -Tpng -o tree.png");

	return NOT_ERROR;
}

static tree_error_t print_edge (node_t* ptr_node, FILE* dump_file)
{
	assert (ptr_node);
	assert (dump_file);

	if ((ptr_node -> left) != NULL)
	{
		fprintf (dump_file, "%ld -> %ld\n\t", ptr_node -> data, (ptr_node -> left) -> data);
		print_edge (ptr_node -> left, dump_file);
	}

	if ((ptr_node -> right) != NULL)
	{
		fprintf (dump_file, "%ld -> %ld\n\t", ptr_node -> data, (ptr_node -> right) -> data);
		print_edge (ptr_node -> right, dump_file);
	}

	return NOT_ERROR;
}
