#include<iostream>
#include "ex2.h"
using namespace std;

void string_sort(char* a, int length)
{
  for (int count = 0 ; count < length ; count++)
    //swap_array(&a[count],&a[minimum_from_string(a,count,length)]);
    swap_array(a+count,a+minimum_from_string(a,count,length));
}

int minimum_from_string(char* a, int position, int length)
{
  int min_index = position;
  cout << "position" << position << endl;	

  // a[4] is the same as *(a+4)
  for (int count = position + 1 ; count < length ; count ++)
       
    if (a[count] + 31 < 97 || a[count] < a[min_index])
      {     
	cout << "a[count]" << a[count] << "    " << "a[min_index]" << char(a[min_index]) << endl;
	min_index = count;
      }
  return min_index;
}
	
void swap_array(char* first, char* second)
{
  char temp = *first;
  *first = *second;
  *second = temp;
  cout << "swaping : " <<*first << "&" << *second <<endl;
}
