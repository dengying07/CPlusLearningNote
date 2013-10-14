	/* This program prints out a conversion table of temperatures, after
	prompting the user for upper and lower bounds of the table in
        Fahrenheit, and the temperature difference between table entries. */ 

	#include <iostream>
	using namespace std;
        int print_preliminary_message ();
        void input_table_specifications(int &this_lower, int &this_upper, int &this_step);
        int print_message_echoing_input(int lower, int upper, int step);
int print_table(int lower, int upper, int step);
double celsius_of(int fahr);
double absolute_value_of(int fahr);	


	/* START OF MAIN PROGRAM */
	int main() 
	{	
		int lower = 0; /* the lowest Fahrenheit entry in the table */
		int upper = 0; /* the highest Fahrenheit entry in the table */
		int step = 1;  /* difference in Fahrenheit between entries */

		/* print a message explaining what the program does: */
		print_preliminary_message();
	
		/* prompt the user for table specifications in Fahrenheit: */
		input_table_specifications(lower, upper, step);
	
		/* print appropriate message including an echo of the input: */
		print_message_echoing_input(lower, upper, step);
	
		/* Print the table (including the column headings): */
		print_table(lower, upper, step);

		return 0;
	}
	/* END OF MAIN PROGRAM */

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

