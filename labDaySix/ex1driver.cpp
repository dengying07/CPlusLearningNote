#include <iostream>
#include "ex1.h"
using namespace std;
int main()
{
  int n;
  cout << "plz input the number of elements you want in the array: " << endl ; 
  cin >> n;
  int a[n] ;
  input_array(a,n);
  display_array (a,n);
  int b[n] ;
  copy_array(b,a,n);
  standard_deviation(a,n);
  cout << "finally it ends! "<< endl;
}
