/**************************************

Add the following 3 functions to Program 7.5.1 from Lecture 7, and modify the program to test them:

    The function

    	void add_after(node_ptr &list, char a_word[], char word_after[])

    which inserts a node containing "word_after" in the linked list "list", after the first occurrence of a node containing "a_word". If "list" does not contain such a node, the function leaves it unchanged.
    The function

    	void delete_node(node_ptr &a_list, char a_word[])

    which deletes the first node in "a_list" which contains "a_word".
    The function

    	void list_selection_sort(node_ptr &a_list)

    which sorts a list alphabetically (use your answer to Question 2 to help). 

Example input/output might be:

	Enter first word (or '.' to end list): the
	Enter next word (or '.' to end list): quick
	Enter next word (or '.' to end list): brown
	Enter next word (or '.' to end list): fox
	Enter next word (or '.' to end list): jumped
	Enter next word (or '.' to end list): over
	Enter next word (or '.' to end list): the
	Enter next word (or '.' to end list): lazy
	Enter next word (or '.' to end list): dog
	Enter next word (or '.' to end list): .
	
	THE LIST IS NOW:
	the quick brown fox jumped over the lazy dog
	
	AFTER WHICH WORD WOULD YOU LIKE TO ADD AN EXTRA WORD? the
	WHICH WORD WOULD YOU LIKE TO ADD? very
	
	THE LIST IS NOW:
	the very quick brown fox jumped over the lazy dog 
	
	WHICH WORD WOULD YOU LIKE TO DELETE? lazy
	
	THE LIST IS NOW:
	the very quick brown fox jumped over the dog
	
	AFTER SORTING, THE LIST IS:
	brown dog fox jumped over quick the the very

Hints:
In words, a possible algorithm to add a node is:
(i) Use an extra node pointer to find and identify the node after which you would like to add the new node,
(ii) Use a second extra node pointer to create the new node,
(iii) Make appropriate adjustments to the pointer inside the node you identified in step (i) and the pointer inside the new node you created in step (ii).

A possible algorithm to delete a node is:
(i) Position one extra pointer pointing to the node before the one you wish to delete, and another extra pointer pointing to the actual node to be deleted.
(ii) Make an appropriate adjustment to the pointer inside the node before the one to be deleted, so that it skips over the obsolete node and points straight to the one after.
(iii) Delete the obsolete node.

The algorithm given in Lecture 6 to sort an array can be straightforwardly adapted to sort a linked list.

*******************************************/

/* Program 7.5.1 from C++ Programming Lecture notes  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 28th September 2013    */

/* This program creates and prints out a linked list of strings. */ 

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_WORD_LENGTH = 80;

/* definition of a node */
struct Node;
typedef Node *Node_ptr;

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

static char abc[] = {'a','b','c','\0'};
static char def[] = {'d','e','f','\0'};
/* MAIN PROGRAM */
int main()
{
	Node_ptr my_list = NULL;

	assign_list(my_list);

	cout << "\nTHE LIST IS NOW:\n";
	print_list(my_list);

	add_after(my_list, abc, def);
	cout << "\n after adding, THE LIST IS NOW:\n";
	print_list(my_list);

	delete_node(my_list, def);
	cout << "\n  after deleting, THE LIST IS NOW:\n";
	print_list(my_list);

	list_selection_sort(my_list);
	cout << "\n   after sorting, THE LIST IS NOW:\n";
	print_list(my_list);
			
	return 0;
}
/* END OF MAIN PROGRAM */
	
/* DEFINITION OF FUNCTION "assign_list" */
void assign_list(Node_ptr &a_list)
{
	Node_ptr current_node, last_node;
	
	assign_new_node(a_list);
	cout << "Enter first word (or '.' to end list): ";
	cin >> a_list->word;
	if (!strcmp(".",a_list->word))
	{
		delete a_list;
		a_list = NULL;
	}
	current_node = a_list;
	
	while (current_node != NULL)
	{
		assign_new_node(last_node);
		cout << "Enter next word (or '.' to end list): ";
		cin >> last_node->word;
		if (!strcmp(".",last_node->word))
		{
			delete last_node;
			last_node = NULL;
		}
		current_node->ptr_to_next_node = last_node;
		current_node = last_node;
	}
}	
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "assign_new_node" */
void assign_new_node(Node_ptr &a_node)
{
        a_node = new (nothrow) Node;
	a_node->ptr_to_next_node = NULL;
	if (a_node == NULL) 
	{
		cout << "sorry - no more memory\n"; 
		exit(1);
	}
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "print_list" */
void print_list(Node_ptr a_node)
{
	while (a_node != NULL)
	{
		cout << a_node->word << " ";
		a_node = a_node->ptr_to_next_node;
	}
}
/* END OF FUNCTION DEFINITION */

/* aim: inserts a node containing "word_after" in the linked list "list", after the first occurrence of a node containing "a_word". If "list" does not contain such a node, the function leaves it unchanged.
   The function */
void add_after(Node_ptr &list, char a_word[], char word_after[])
{
  Node_ptr temp = list;
  while (temp && temp->ptr_to_next_node)
    {
      //Compare node labels
      if (strcmp(temp->word,a_word)==0)
	{
	  //Create new node pointer
	  Node_ptr new_node_ptr;

	  //Initialize new node pointer
	  assign_new_node(new_node_ptr);

	  //Attach next node to new node
	  new_node_ptr -> ptr_to_next_node = temp -> ptr_to_next_node;
	  
	  
	  temp -> ptr_to_next_node= new_node_ptr;
	  cout << "\n word <" << word_after << " inserted at position pointer = " << new_node_ptr << endl ; 
	  break;
	}
      temp = temp->ptr_to_next_node;
      cout << "esfet" << endl;
    }
}

/*aim: deletes the first node in "a_list" which contains "a_word".
    The function*/
void delete_node(Node_ptr &a_list, char a_word[])
{
  Node_ptr temp = a_list;
  while (temp && a_list->ptr_to_next_node)
    {
      if (strcmp(temp->ptr_to_next_node->word,a_word)==0)
	{
	  Node_ptr del_node_ptr = a_list->ptr_to_next_node;
	  temp->ptr_to_next_node = temp->ptr_to_next_node->ptr_to_next_node;
	  delete del_node_ptr;
	}
      temp = temp->ptr_to_next_node;
    }
}

/*aim: sorts a list alphabetically (use your answer to Question 2 to help).*/
void list_selection_sort(Node_ptr &a_list)//how can i compare char[]?
{
  Node_ptr list = a_list;
  Node_ptr temp = list;
  Node_ptr swap = list;
  char min[MAX_WORD_LENGTH];
  for (int i = 0; i<MAX_WORD_LENGTH;i++)
    {
      min[i] = list->word[i];
    }

  for (;list;list = list->ptr_to_next_node) //why is the array getting errors?
    {
      for(temp = list;temp;temp = temp->ptr_to_next_node)
	{
	  for (int i = 0 ; temp ->word[i];i++)//find a smaller value of word and put it in min
	    {
	      if((temp->word[i])<min[i])
		{
		  //min = temp -> word;
		swap = temp;
		break;	
		}
	    }
	}
      // temp->word = a_list->word; //swap the word of the smallest with the current pointer of the first for loop
      // a_list->word = min;

      temp = list;//swap the pointer of the smallest with the current pointer of the first for loop
      list = swap;
    }
}
