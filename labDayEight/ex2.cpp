/********************
(a) Write two recursive functions "print_list_forwards(...)" and "print_list_backwards(...)", which print the linked lists from Lecture 7 respectively forwards and backwards on the screen. (The function "print_list_forwards(...)" should behave in exactly the same way as the function "print_list(...)" from Lecture 7). Alter Program 7.5.1 in a suitable way to test the functions. Your program should be able to produce output similar to the following:

	Enter first word (or '.' to end list): the
	Enter next word (or '.' to end list): quick
	Enter next word (or '.' to end list): brown
	Enter next word (or '.' to end list): fox
	Enter next word (or '.' to end list): .

	THE LIST FORWARDS IS:
	the quick brown fox

	THE LIST BACKWARDS IS:
	fox brown quick the
Hint: Look at Program 8.2.1 when designing "print_list_backwards()".

(b) Write and test an iterative (i.e. non-recursive) version of the function "print_list_backwards(...)". (Which definition did you find easier?)

*********************/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "ex2.h"
using namespace std;

void print_list_forwards(Node_ptr a_node)
{
  if (a_node)
    {
    cout << a_node->word << " ";
    print_list_forwards(a_node->ptr_to_next_node);
    }
    return;
}

void print_list_backwards(Node_ptr a_node) /*magical things happen here >v< */
{
  if(a_node)
    {
      print_list_backwards(a_node->ptr_to_next_node);
      cout << a_node->word << " ";
    }
  return;
}

void iterative_print_backwards(Node_ptr &a_node) /*how do I dynamically allocate memory for the pointers???*/
{
  /*maybe make another list will be a good way to solve it..but I'll just write a finite size array..to make it less miserable*/

  Node_ptr addr[ITERATIVE_PRTINT_LIMIT];
  for (int i = 0;i < ITERATIVE_PRTINT_LIMIT ; i++)
    //another segmentation fault happened when I tried to initialize an array of string and put the words in it. 
    //still having it when defining the array as Node_ptr. it's gone after I add the 'if' sentence
    {
      addr[i] = NULL;
      if(a_node != NULL)
	{
	  addr[i] = a_node;
	  a_node = a_node -> ptr_to_next_node;
	}
    }
  for (int i = ITERATIVE_PRTINT_LIMIT-1; i >= 0; i--)
    {
      if(addr[i] != NULL)
	cout <<addr[i]->word << " "; 
    }
}
    

