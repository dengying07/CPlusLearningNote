#include <iostream>
	#include <fstream>

	using namespace std;

	int main()
	{
		char character;
		int integer;
		ofstream out_stream;
		ifstream in_stream;
	
		/* Create a file containing two integers */
		out_stream.open("Integers");
		out_stream << 123 << ' ' << 456;
		out_stream.close();
	
		/* Attempt to read a character, then an integer,
		   then a character again, then an integer again,
		   from the file "Integers" just created.         */
		in_stream.open("Integers");
		in_stream >> character >> integer;
		cout << "character: '" << character << "'\n";
		cout << "integer: " << integer << "\n";
		in_stream >> character >> integer;
		cout << "character: '" << character << "'\n";
		cout << "integer: " << integer << "\n";
		in_stream.close();
	
		return 0;
	}
