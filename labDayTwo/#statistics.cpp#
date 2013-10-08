#include <iostream>
#include <string>
using namespace std;
double average(int a_number, double *a_digit);
double standard_deviation(int e_number, double *e_digit);
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
double average(int a_number, double *a_digit)
{
  double a_average = 0;
  for(int i=0 ; i < a_number; i++)
    {
      a_average +=  *a_digit++;
    }
  a_average /= a_number;
  return a_average;
}
double standard_deviation(int s_number, double *s_digit)
{
  double s_average = average(s_number, s_digit);
  double s_sdeviation = 0;
  for(int i=0; i < s_number; i++)
    {
      s_sdeviation += ((*s_digit) - s_average)*((*s_digit) - s_average);
      cout << s_sdeviation;
      s_digit++;
    }
  s_sdeviation /= s_number;
  return s_sdeviation;
}
