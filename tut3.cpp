#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

// Tutorial Exercise 3
// Routines for Manipulating a Singly Linked List 
//
// Also available from
//   http://www.doc.ic.ac.uk/~wjk/C++Intro/tut3.cpp
//
// Try to understand what the routines do using just pen and paper. 
// Then experiment with the routines on a computer and see if you
// can adapt them to construct and manipulate doubly linked lists
// (i.e. where each node has a next and a prev pointer).

// one node in the linked list looks like this
struct Node {
  char word[80];  // a string
  Node *next;     // a pointer to the next node
};

// this function returns a pointer to a newly created node
// note that we set the pointer to the next node to NULL
Node *create_new_node(const char *contents) {
  Node *new_node = new (nothrow) Node;
  assert(new_node != NULL);
  strcpy(new_node->word, contents);
  new_node->next = NULL;
  return new_node;
}

// set up an empty list
void initialise_list(Node *&front, Node *&rear) {
  front = rear = NULL;
}

// add a node to the front of the list
void add_to_front(Node *&front, Node *&rear, const char *word) {
  Node *item = create_new_node(word);
  
  // empty list case
  if (!front) {
    front = rear = item;
    return;
  }

  // default case
  item->next = front;
  front = item;
}

// add a node to the rear of the list
void add_to_rear(Node *&front, Node *&rear, const char *word) {
  Node *item = create_new_node(word);
  
  // empty list case
  if (!front) {
    front = rear = item;
    return;
  }

  // default case
  rear->next = item;
  rear = item;
}

// output the list to the screen
void print_list(Node *front) {
    for (Node *current = front; current; current=current->next) 
      cout << "[" << current->word << "] ";
    cout << endl;
}

// delete the node containing the target string
void delete_node(Node *&front, Node *&rear, const char *target) {
  Node *p = front, *q = NULL;

  // find the node we want to delete
  for (p=front; p && strcmp(p->word, target); p=p->next) 
    q = p;

  if (p == NULL) {
    cout << "could not find the word " << target << " in the list." << endl;
    return;
  }

  // p now points to the node we want to delete
  // q now points to the node before the one we want to delete
  
  // store the targets next pointer and delete the target
  Node *link = p->next;
  delete p;

  // handle the case that the target is the front (or equivalently q == NULL)
  if (p==front) {
    front = link;
    if (front == NULL)
      rear = NULL;
    return;
  }

  // update the next pointer of the node before the one being deleted
  q->next = link;

  // handle the case that the target is the rear
  if (p == rear) 
    rear = q;
}

// insert a word into a sorted list
void add_sorted(Node *&front, Node *&rear, const char *new_word) {
  Node *p = front, *q = NULL;

  // find the node we want to insert after
  for (p=front; p && (strcmp(p->word, new_word) < 0); p=p->next) 
    q = p;

  // p points to the node we want to insert before
  // q points to the node we want to insert after

  if (q==NULL) {
    add_to_front(front, rear, new_word);
    return;
  }

  if (p==NULL) {
    add_to_rear(front, rear, new_word);
    return;
  }

  // otherwise create the new node 
  Node *new_node = create_new_node(new_word);

  // and insert it after q and before p
  new_node->next = p;
  q->next = new_node;
}

// delete all items in the list
void delete_list(Node *&front, Node *&rear) {
  // keep deleting items from the front of the list until there is nothing left
  while (front != NULL) {
    Node *link = front->next;
    delete front;
    front = link;
  }
  rear = NULL;
}

int main() {
  // front and rear point to the first and last nodes in the linked
  // list respectively
  Node *front, *rear;

  // initialise the list
  initialise_list(front, rear);

  // add some nodes
  add_to_front(front, rear, "sat");
  add_to_rear(front, rear, "cat");
  add_to_front(front, rear, "mat");
  add_to_rear(front, rear, "hat");

  print_list(front);
  cout << endl;

  // delete a node
  delete_node(front, rear, "mat");

  print_list(front);
  cout << endl;

  // delete the list
  delete_list(front, rear);

  // add some elements in ascending order
  add_sorted(front, rear, "sat");
  add_sorted(front, rear, "cat");
  add_sorted(front, rear, "hat");
  add_sorted(front, rear, "mat");
  add_sorted(front, rear, "bat");
  add_sorted(front, rear, "rat");

  print_list(front);
  cout << endl;

  delete_list(front, rear);

  return 0;
}
