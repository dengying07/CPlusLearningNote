/******************
The Fibonacci sequence a(1), a(2), a(3), ..., a(n), ... is defined by

a(1) =1
a(2) = 1
a(n) = a(n-1) + a(n-2), for all n > 2
This generates the sequence

1, 1, 2, 3, 5, 8, 13, 21, ...

Write a C++ function "fibonacci(...)" that computes the Fibonacci number corresponding to its positive integer argument, so that, for example, fibonacci(7) == 13.
*******************/
#include <iostream>
using namespace std;

int fibonacci(int n)
{
  int result=0;
  if (n>2)
    result = fibonacci(n-2)+fibonacci(n-1);  
  else if(n<=2)
    result = 1;
  return result;
  /*it's so simple that I dont want to add any notes here :p  */
}
int main()
{
  int n;
  cout << "plz input a index for the Fibonacci sequence" << endl;
  cin>>n;
  cout << "the Fibonacci value for this index will be: " << "F<" << n << "> = " << fibonacci(n) << endl;
}
