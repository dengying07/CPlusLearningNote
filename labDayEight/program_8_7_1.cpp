/* Program 8.7.1 from C++ Programming Lecture notes  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 30th September 2001    */

/* This program illustrates the Quick Sort algorithm. */ 

#include<iostream>
using namespace std;

const int MAX = 11;

/* Function which sorts the elements in list from 
list[left] to list[right] into ascending order */
void quick_sort(int list[MAX], int left, int right);

/* Function to swap the values of two integer variables */
void swap(int& first, int& second);

/* Function to display the contents of the array "a" up to element a[length-1] */
void display(int a[], int length);

/* START OF MAIN PROGRAM */
int main()
{
	int list[MAX];
	int count;
	
	for (count = 0 ; count < MAX ; count++)
	{
		cout << "Enter value of element " << count << ": ";
		cin >> list[count];
	}
	
	cout << "\n\nBefore Quick Sort:\n\n";
	
	display(list,MAX);
	
	quick_sort(list, 0, MAX -1);
	
	cout << "\n\nAfter Quick Sort:\n\n";
	
	display(list,MAX);
	
	return 0;
}
/* END OF MAIN PROGRAM */

/* FUNCTION DEFINITION OF quick_sort: */
void quick_sort(int list[], int left, int right)
{
	int pivot, left_arrow, right_arrow;
	
	left_arrow = left;
	right_arrow = right;
	pivot = list[(left + right)/2];
	
	do
	{
		while (list[right_arrow] > pivot)
			right_arrow--;
		while (list[left_arrow] < pivot)
			left_arrow++;
		if (left_arrow <= right_arrow)
		{
			swap(list[left_arrow], list[right_arrow]);
			left_arrow++;
			right_arrow--;
		}
	}
	while (right_arrow >= left_arrow);
	
	if (left < right_arrow)
		quick_sort(list, left, right_arrow);
	if (left_arrow < right)
		quick_sort(list, left_arrow, right);
}
/* END OF FUNCTION */

/* DEFINITION OF FUNCTION "swap" */
void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}
/* END OF FUNCTION DEFINITION */

/* DEFINITION OF FUNCTION "display" */
void display(int a[], int length)
{
	for (int count = 0 ; count < length ; count++)
		cout << a[count] << " ";
	cout << "\n\n";
}
/* END OF FUNCTION DEFINITION */
