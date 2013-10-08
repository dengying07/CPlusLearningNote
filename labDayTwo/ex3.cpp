#include <iostream>
#include <string>
#include "ex3.h"
using namespace std;
int main()
{
  int number =-1;
  string code[4] = {"first", "second", "third", "fourth"};
  cout << "This program tests the functions in the 'statistics.h' header file." << endl;
  double digit[4]= {-1,-1,-1,-1};
  double *p;
 
  while (number!=0)
    {
      cout << "Do you wish to test 1,2,3,or 4 numbers (enter 0 to end the program)" << endl;
      cin >> number ;
       if(number > 0)
	{
	  for (int i = 0; i < number;i++)
	    {
	      cout << "Enter " << code[i] << " value:" ;
	      cin >> digit[i];
	    }
	  p = digit;
	  double average_o = average(number,p);
	  double sdeviation_o = standard_deviation(number,p);
	  
	  cout << "Average: " << average_o << " .\nStandard deviation: " << sdeviation_o << " .\n" ;
	} 
    }
}
