#include <iostream>
#include "ex1.h"
using namespace std;
int main()
{
  int n;
  cout << "plz input the number of elements you want in the array: " << endl ; 
  cin >> n;
  int a[n] ;
  input_array(&a[0],n);
  display_array (&a[0],n);
  int b[n] ;
  copy_array(&b[0],&a[0],n);
  standard_deviation(&a[0],n);
  cout << "finally it ends! "<< endl;
}
