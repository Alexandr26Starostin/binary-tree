#ifndef NEW_NODE_H
#define NEW_NODE_H

tree_error_t find_position_node (node_t* ptr_new_node, node_t* ptr_parent);
tree_error_t creat_new_node     (node_t** ptr_ptr_node, long value, int line, const char* file);
tree_error_t attach_node        (long value, node_t* ptr_first_parent, int line, const char* file);

#endif
