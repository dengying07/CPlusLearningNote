/******************************************
Write a function "no_repetitions(...)" which removes all repetitions of characters from a string. Test the function in a suitable main program, which should be able to reproduce the following input/output:

	Type in a string: This string contains repeated characters
	The string without repetitions is: This trngcoaepd

Hint: Like most programming problems, this exercise is much easier if you use functional abstraction.

*********************************************/


#include <iostream>
#include <cstring>
using namespace std;

void no_repetitions(char* a) 
{
  char *position = a;
  while (*(a++))
    {
      for (position = a ; *position ;  )
	{
	  if(*position == ' ')
	    *position = *(position+1);
	  else 
	    {
	      *a = *position;
	      position++;
	    }
	}
    }
}


int main()
{
  string my_string;

  cout << "plz input a string: " << endl;
  getline(cin, my_string);

  cout << "before the func the string is : " << my_string << endl;

  no_repetitions((char*)my_string.c_str());

  cout << "after the func the string is : " << my_string << endl;
  
}
