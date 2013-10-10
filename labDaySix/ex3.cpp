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
  char *origin  = a;
  char *position = a;
  char *cursor = a;

  /*while (*(a))
    {
    cout << "the element tested is :" << *a << "**********"<<endl;
    for (position = a+1 ; *position ;  )
    {
    cout << "testing : "<< *position << "////////" << endl ;
    if(*position == ' ')
    {
    *position = *(a+1);
    cout<< "blank goes:" << *position << endl;
    position++;
    }	  
    else if(*position == *a)
    {
    *(position) = *(position+1);
    *(position +1 ) = ' ';
    cout << "same ele goes:" <<*a <<"  "<<*(position-1)<<"  "<< *position << endl;
    position++;
    }
    else if(*position != *a && *position)
    {
    cout << "diff goes: " << *position << endl;
    position ++;
    }
    else 
    {
    cout << "ahhh"<<endl;
    continue;

    }
    }
    a++;
    }*/  /*oh I finally realize I'm just being silly...let's leave the optimising thing to the future!!!*/
   
for ( position = a ; *position ; position ++)
    {
      for (cursor = position+1; *cursor ; cursor++)
	{
	  if (*position == *cursor)
	    { cout << "if1"<< *position << endl;
	      *cursor = ' ';}
	}
    } 

  for ( position = a ; *position ; position ++)
    {
      if (*position  == ' ')
	{	origin = position;
	  cout<<"if2"<<*position<<endl;
	  break;}
    }
  for (position = origin; *position; position ++)
    {
      for( cursor = position+1 ; *cursor ; cursor++)
	{
	  if (*cursor != ' ')
	    {
	      *position = *cursor;
	      *cursor = ' ';
	      cout<<"if3"<<*position<<endl;
	      continue;

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
