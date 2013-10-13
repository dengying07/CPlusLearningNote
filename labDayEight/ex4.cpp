/*******************
Binary Search. Binary Search is recursively defined algorithm for searching through a sorted list (array) to find a position of a particular value. It is particularly efficient for large lists, since it avoids the need to search sequentially (i.e. one value at a time).

The idea is as follows. Suppose we want to find a position of the value v in the previously sorted array a[]. We first look at the value stored half way along a[]. If this happens to be v, we are finished, and we can simply return this middle position. However, if the value at the middle position is less than v, we now know we only have to search the 2nd half of the list, and so we repeat the search procedure just with this half of the list. Similarly, if the value at the middle position is greater than v, we now know we only have to search the 1st half of the list. (Imagine looking for the page containing the definition for a particular word in a dictionary. If using binary search, you would start at the middle page, and then just restrict your attention either to the part of the dictionary before this page, or the half after this page, depending on what words you saw on the middle page.) Binary search is discussed in more detail in Savitch, Section 14.3.

Write a function with function declaration

	int binary_search(int value, int list[], int first, int last);
which searches the values in the array "list[]" from "list[first]" to "list[last]" to find an array element with value "value". If it finds "value", it returns the position of "value" in "list[]". Otherwise it returns -1. For example, given the array


the call

	binary_search(24, list, 0, 10);
returns the value 9, the call

	binary_search(24, list, 2, 6);
returns the value -1, and the call

	binary_search(22, list, 0, 10);
either returns the value 7 or returns the value 8.
************************/
#include<iostream>
using namespace std;
int binary_search(int value, int list[], int first, int last)
{
  int pos = -1;
  int temp = (int)(first + last) / 2;
  if (list[last] == value)
    return last;
  if (list[first] == value)
    return first;
  if (first != last && (first != temp && last != temp))
    {
      if (list[temp] == value)
	pos = temp;
      else if(list[temp] < value)
	pos = binary_search(value, list, temp, last );
      else if(list[temp] > value)
	pos = binary_search(value, list, first, temp );
    }
  else 
    return -1;
  return pos;
}

int main()
{
  int wanted, first, last;
  int list[] = {2,2,3,5,8,14,16,22,22,24,30};
  cout << "plz input wanted value, followed by the FIRST and LAST position for the search.\n";
  cin >> wanted >> first >> last;
  if(binary_search(wanted, list, first, last) != -1)  
    cout << "the value is at position:" << binary_search(wanted, list, first, last) << endl;
  else 
    cout << "not in the array.\n";
}
