#include <iostream>
using namespace std;

void print_pyramid(int height);

int main()
{
  int height;
  cout << "This program prints a 'pyramid' shape of a specified height on the screen." << endl;
  cout << "how high would you like the pyramid?" ;
  cin >> height;
  while (height > 30 || height < 1)
    {
      cout << "Pick another height (must be between 1 and 30):" ;
      cin >> height;
    }
  print_pyramid(height);
  return 0;
}

void print_pyramid(int height)
{
  for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < height*2; j++)
	{
	  if (j < height-i-1)
	    cout << " ";
	  else if (j > height+i)
	    cout << " ";
	  else
	    cout<< "*";
	}
      cout << endl;
    }
}
