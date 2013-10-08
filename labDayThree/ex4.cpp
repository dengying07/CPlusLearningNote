#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream in1;
  in1.open("ex4.cpp");
  ifstream in2;
  int count=0;
  char contentIn1;
  char contentIn2;
  in1.get(contentIn1);
  while ( ! in1.fail())
    {
      in1.get(contentIn1);
      count++;
    }
  in1.close();
  cout <<"start print"<< count<< "letters"<<endl;

  for (int i = 0; i < count; i++)
    {
      in2.open ("ex4.cpp");
      for (int j = 0; j < count - i; j++) 
	{
	  in2.get(contentIn2);
	  
	}
      in2.close();
      cout << contentIn2;
    }


}
