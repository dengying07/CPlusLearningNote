#include <iostream>
using namespace std;

int main()
{
  char i;
  cout << "Please type in a character:";
  cin >> i;
  int cal;
  string letter;
  if((int)i <= 122 && (int)i >= 97)
    {
      cal = -32;
      letter = "upper";
      char j = (char)((int)i+cal);
      cout << "The " << letter << "case character corresponding to <" << i << "> is <" << j << ">" <<endl;
    }
  else if ((int)i <= 90 && (int)i >= 65)
    {
      cal = 32;
      letter = "lower";
      char j = (char)((int)i+cal);
      cout << "The " << letter << "case character corresponding to <" << i << "> is <" << j << ">" <<endl;
    }
  else 
    {
      cout << "<" << i << "> is not a letter" << endl;
    }

  
}

