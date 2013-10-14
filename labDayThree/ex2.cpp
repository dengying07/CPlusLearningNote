#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  ifstream in;
  ofstream out;
  cout << "Testing : " << 16/2 << " = " << 4*2 << ".\n\n";
  out.open("WithoutContents.txt");
  in.open("ex2.cpp");
  char content;
  while (!in.eof())
    {
      in.get(content);
      if(content == '/') /*do not print this comment*/
	{
	  in.get(content);
	  if(content == '*')
	    while ( (in.get() != '*') && (in.get() != '/')){;}
	}
      out.put(content);
    }
  in.close();
  out.close();
  return(0);

}
