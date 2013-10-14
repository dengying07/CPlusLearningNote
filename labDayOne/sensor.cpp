#include <iostream>
#include <iomanip>
#include <cmath>

// You are in charge of the climate control in the International Space Station
// where the requirement is for the temperature to be maintained at 20 degrees.
// You are given the task of computing the average temperature in the station based
// on sensor readings. A student writes the following code. What will happen?

using namespace std;

float sensor_reading() { // will be taken over by a hardware sensor but for
  return 20.0;           // now we always return a comfortable 20 degrees
}

int main() {

  float total = 0.0;
  for (int n=1; n<100000000 ; n++) {
    total += sensor_reading();
    if ((n % 100000)==0) {
      cout << total<< n <<endl;
      float average = total/n;
      cout << setw(20) << "the average of " << setw(20) << n << " readings is " << average << endl;      
      if (average > 20.1)
	cout << "# FREEZER ON" << endl;
      if (average < 19.9)
	cout << "# HEATER ON" << endl;
    }
  }
  return 0;
}
