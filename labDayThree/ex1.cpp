#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  ifstream contents;
  contents.open("ex1.cpp");
  char content;
  //n >> content;
  //ut << content;

  while(!contents.fail())
    {
      contents.get(content);
      cout << content;
      //cin>>content;
    }
  contents.close();
  return 0;
}

