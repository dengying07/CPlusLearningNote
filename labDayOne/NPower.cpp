#include <iostream>
using namespace std;
int main()
{
  int i = -1;
  int n = 0;
  while (i<0)
    {
      cout << "Please enter a POSITIVE NUMBER and a POWER" <<endl;
      cin >> i >> n;
    }
  int sum = i;
  for (int j = 1; j < n; j++)
    {      
      sum = sum*i;
    }
  cout << "The <" << n <<">th power of <" << i << "> is <" << sum << ">." << endl; 

}

