#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream in;
  in.open ("ex3.cpp");
  int count;
  while (!in.fail())
    {
      char content;
      if( (in.get(content)) != "\n")
	{
	  count++;
	}
      
    }
  cout << "The number of characters in my cpp file is : " << count << "." << endl;
  in.close();
  return 0; /*trial*/
}
