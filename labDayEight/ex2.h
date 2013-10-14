#ifndef EX2_H
#define EX2_H
/* definition of a node */
struct Node;
typedef Node *Node_ptr;

const int MAX_WORD_LENGTH = 80;
const int ITERATIVE_PRTINT_LIMIT = 100;

struct Node
{
	char word[MAX_WORD_LENGTH];
	Node_ptr ptr_to_next_node;
};

/* Function to assign a linked list to "a_node" */
void assign_list(Node_ptr &a_list);

/* Function to assign a new dynamic node variable to "a_node" */
void assign_new_node(Node_ptr &a_node);

/* Function to print the strings in the list "a_node" */
void print_list(Node_ptr a_node);

void add_after(Node_ptr &list, char a_word[], char word_after[]);

void delete_node(Node_ptr &a_list, char a_word[]);

void list_selection_sort(Node_ptr &a_list);

void word_exchange(Node_ptr &list, Node_ptr &temp, char min[]);

/*the function to print the list forwards*/
void print_list_forwards(Node_ptr a_node);

/*the function to print the list backwards*/
void print_list_backwards(Node_ptr a_node);

/*an iterative way to print backwards*/
void iterative_print_backwards(Node_ptr &a_node);
#endif
