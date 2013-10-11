/********************************
Write a Boolean valued function which returns "True" if its first string argument is alphabetically smaller than its second string argument, "False" otherwise. You may assume that the two strings contain only lower case letters, and no blanks or other non-alphabetic characters. Test your function with a suitable main program. When you are satisfied it works properly, convert the function to pointer arithmetic syntax, and check that it still behaves in the same way.
********************************/
#include <iostream>
#include <cstring>
using namespace std;

  static string str1 = "asdfeafew";
  static string str2 = "wefwjefiwej";

bool comp_string(string str1, string str2)//simply comparing strings
{
  if (str1.compare(str2)<0)
    {
      return 1;    
    }
  else 
    return 0;
}

bool comp_str_ptr(string *str1, string *str2) //use pointers to strings
{
if ((*str1).compare(*str2)<0)
  {
return 1;    
}
 else 
   return 0;
}


int main()
{
switch(comp_str_ptr(&str1, &str2))//comp_string(str1, str2))
  {
 case 1: cout << "string1 is smaller" << endl; break;
 case 0: cout << "string1 is larger" << endl; break;
 default:cout << "error!" <<endl;
}
}
