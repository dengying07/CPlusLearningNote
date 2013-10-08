	#include <iostream>
	using namespace std;

/* FUNCTION TO CONVERT FAHRENHEIT TO CELSIUS */
	double celsius_of(int fahr)
	{
		return (static_cast<double>(5)/9) * (fahr - 32);
	}
	/* END OF FUNCTION */

	/* FUNCTION TO CONVERT FAHRENHEIT TO ABSOLUTE VALUE */
	double absolute_value_of(int fahr)
	{
		return ((static_cast<double>(5)/9) * (fahr - 32)) + 273.15;
	}
	/* END OF FUNCTION */

	/* FUNCTION TO CONVERT FAHRENHEIT TO CELSIUS */
	int print_preliminary_message ()
	{
	  cout << "This program prints out a conversion table of temperatures." << endl << endl;
	  return 0;
	}
	/* END OF FUNCTION */
  


        void input_table_specifications(int &this_lower, int &this_upper, int &this_step)
	{
	  cout << "Enter the minimum (whole number) temperature you want in the table, in Fahrenheit:" << endl;
	  cin >> this_lower ;
	  cout << "Enter the maximum temperature you want in the table:" << endl;
	  cin >> this_upper ;
	  cout <<"Enter the temperature difference you want between table entries:" << endl;
	  cin >> this_step ;
	}
        /* END OF FUNCTION */
	
        int print_message_echoing_input(int lower, int upper, int step)
	{
	  cout << "Temperature conversion table from " << lower << " Fahtenheit to " << upper << " Fahrenheit, in steps of " << step << " Fahrenheit:" << endl << endl;
	  return 0;
	}
	/* END OF FUNCTION */

        int print_table(int lower, int upper, int step)
	{
	  cout.precision(2);
	  cout.setf(ios::fixed);
	      cout << "Fahrenheit";
	      cout.width(13);
	      cout << "Celsius";
	      cout.width(23);
	      cout << "Absolute Value" << endl;
	      for (int i = lower; i <= upper; i += step)
	    {
	      cout << i << "\t\t" << celsius_of(i) << "\t\t" << absolute_value_of(i) << endl;
	    }
	  return 0;
	}
	/* END OF FUNCTION */
