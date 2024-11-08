#include <stdio.h>

#include "const_in_binary_tree.h"
#include "new_node.h"
#include "print_tree.h"

#define ATTACH_NODE_(value)                                                     \
	status = attach_node (value, ptr_first_node, __LINE__, __FILE__);           \
	if (status) {return status;}                                                \
	                                                                            \
	status = dump_inorder_tree (ptr_first_node);                                \
	if (status) {return status;}                                                \
	                                                                            \
	print_inorder_tree (ptr_first_node);                                        \
	printf ("\n");

//-------------------------------------------------------------------------------------------------------------

int main ()
{
	node_t* ptr_first_node = NULL;
	
	tree_error_t status = creat_new_node (&ptr_first_node, 50, __LINE__, __FILE__);
	if (status) {return status;}

	status = dump_inorder_tree (ptr_first_node);                                
	if (status) {return status;}
	
	print_inorder_tree (ptr_first_node);
	printf ("\n");

	ATTACH_NODE_(12)
	ATTACH_NODE_(5)
	ATTACH_NODE_(15)
	ATTACH_NODE_(70)
	ATTACH_NODE_(60)
	ATTACH_NODE_(17)

	return status;
}