#include <iostream>
#include "ex1.h"
using namespace std;
int main()
{
  cout << "please input the number you want to test." << endl;
  int num;
  while ( cin >> num )
    {
      bool result = test_num(num);
      if (num > 0 && num < 1001)
	{
	  if (result)
	    {
	      cout << "your input <" << num << "> is A PRIME NUMBER." << endl << endl;
	    }
	  else
	    { 
	      cout << "your input <" << num << "> is NOT a prime number." << endl << endl;
	    }
	}
      else
	{
	  cout << "your input <" << num << "> is outside the range." << endl;
	}
      cout << "do you want to test again? input y or n" << endl;
      char confirm;
      cin >> confirm;
      if (confirm == 'n'|| confirm == 'N')
	break;
      else 
	cout << "please input the number you want to test." << endl;
    }
}

