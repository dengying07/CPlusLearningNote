#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  ifstream instream;
  char letter;
  int i,j;
  cout << "CHARACTER";//bbbbbb
  cout.width(26);
  cout << "OCCURRENCES" << endl;
  for (letter = 'a'; letter <= 'z'; letter++)
    {
      cout << letter;
      instream.open("ex5.cpp");
      while(!instream.eof())
	{  
	  // cout << (char)instream.get();    
	  if((char)letter == ((char)instream.get()))
	    i++;
	}
      cout.width(25);
      cout << i << endl;
      i = 0;
      instream.close();
    }

}
