/*************************************
Predict the output of the following program. Run the program to see if your prediction is right.
******************************************/
	#include <iostream>
	using namespace std;
	
	typedef int *IntPtrType;
		
	int main()
	{
		IntPtrType ptr_a, ptr_b, *ptr_c;
	
		ptr_a = new int;
		*ptr_a = 3;
		ptr_b = ptr_a;
		cout << *ptr_a << " " << *ptr_b << "\n";//3,3
	
		ptr_b = new int;
		*ptr_b = 9;
		cout << *ptr_a << " " << *ptr_b << "\n";//3,9
	
		*ptr_b = *ptr_a;
		cout << *ptr_a << " " << *ptr_b << "\n";//3,3
	
		delete ptr_a;
		ptr_a = ptr_b;
		cout << *ptr_a << " " << *&*&*&*&*ptr_b << "\n";//3,3
	
		ptr_c = &ptr_a;
		cout << *ptr_c << " " << **ptr_c << "\n";//0x...,3
	
		delete ptr_a;
		ptr_a = NULL;
	
		return 0;
	}
