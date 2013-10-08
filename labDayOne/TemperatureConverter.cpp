#include <iostream>
using namespace std;
static int lowest = 30;
static int highest = 400;
static int step = 5;
int main()
{
  cout << "Fahrenheit";
  cout.width(13);

  cout << "Celsius";
  cout.width(23);
  
  cout << "Absolute Value";
  cout << endl;
  
  for (int i = lowest; i <= highest; i+= step)
    {
      float j = ((float)i-32)*5/9;

      cout.precision(2);
      cout.setf(ios::fixed);
      
      cout << i << "\t\t" << j << "\t\t" << j+273.13 << endl;

    }
}
