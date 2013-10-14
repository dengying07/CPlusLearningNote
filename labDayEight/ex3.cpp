/*****************
Given positive two integers m and n such that m<n, the greatest common divisor of m and n is the same as the greatest common divisor of m and (n-m). Use this fact to write a recursive definition of the function "greatest_common_divisor(...)", which takes two positive integer arguments and returns their greatest common divisor. Test your function in a suitable main program.
*****************/

#include <iostream>
using namespace std;

int common_divisor(int a, int b)
{
  int div = 1;
  /*to find a divisor, first to find the larger integer and then just do the recursion*/
  if (a>b)
    div = common_divisor(b, a-b);
  else if(a<b)
    div = common_divisor(a, b-a);
  else
    div = a;
  return div;
}

int main()
{
  int a, b;
  cout << "plz input 2 integers: "<<endl;
  cin >> a >> b ;
  cout << "their greatest common divisor is " << common_divisor(a,b) << endl;
}
