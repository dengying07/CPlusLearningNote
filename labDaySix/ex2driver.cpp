#include<iostream>
#include<cstring>
#include"ex2.h"
using namespace std;

const int NO_OF_ARRAY = 15;

int main()
{
  string my_string;
  int count;

  cout << "Enter value of string: ";
  getline(cin, my_string);
  cout <<"\n\n";
  
  cout << "my string is : \n" << my_string << endl;

  int i;
  for (i = 0 ; my_string[i] ; i++);
  string_sort ((char*)my_string.c_str(), i);

  cout << "after sorting, my string is : \n" << my_string << endl; 



}

