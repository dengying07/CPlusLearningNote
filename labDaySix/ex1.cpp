#include <iostream>
#include <fstream>
#include <cmath>
#include "ex1.h"
using namespace std;
void input_array(int a[], int n)
{
  cout << "plz input the values of your array, enter 'return' to end input" << endl;
  for (int i = 0 ; cin >> a[i] ; i++)
    {
      cout << "you've entered: <" << a[i] << "> in <" << i << ">th element." << endl;
      if (i >= n-1)
	break;
    }
  cout << "you've ended input" << endl;
}
void display_array(int a[], int n)
{
  cout << "this is your array:" << endl;
  for (int i = 0 ; i < n ; i++)
    {
      cout << " a[" << i << "] = " << a[i] << endl;
    }
  cout << "end of array." << endl;
}
void copy_array(int a[], int b[], int n)
{
  cout << "start copy." << endl;
  for (int i = 0 ; i < n ; i++)
    {
      a[i] = b[i];
      cout << "<" << i << ">th element of copied array: " << a[i] << endl; 
    }
  cout << "copy done" << endl;
}
double standard_deviation(int a[], int n)
{
  double aver = 0;
  double stdev = 0;
  cout << "calculating standard deviation " << endl;
  for (int i = 0 ; i < n ; i++)
    {
      aver += a[i];
    }
  aver /= n;
  cout << "average is : " << aver << endl;
  for (int i = 0 ; i < n ; i++)
    {
      stdev += ( a[i] - aver ) * ( a[i] - aver );
    }
  stdev /= n;
  stdev = sqrt (stdev);
  cout << "standard deviation is : " << stdev << endl;
  cout << "finished calculation" << endl; 
  return stdev;
}
