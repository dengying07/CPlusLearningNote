/******************************
Using two-dimensional arrays, write a function (and a corresponding program to test it) which multiplies an mxn matrix of integers by an nxr matrix of integers. Use global constant declarations before the main program to give test values for m, n and r. Example input/output might be:

	INPUT FIRST (2x2) MATRIX:
	Type in 2 values for row 1 separated by spaces: 3 4
	Type in 2 values for row 2 separated by spaces: 5 7
	INPUT SECOND (2x2) MATRIX:
	Type in 2 values for row 1 separated by spaces: 1 1
	Type in 2 values for row 2 separated by spaces: 2 2
	
	           3     4
	           5     7 
	TIMES
	           1     1
	           2     2 
	EQUALS
	           11    11
	           19    19
*****************************/

#include <iostream>
using namespace std;

const int m = 3,
n = 3,
r = 3;

void multiply_matrix(int a[][n], int b[][r], int c[][r]) 
{
  for(int i = 0 ; i < m ; i++)
    {
            for(int j = 0 ; j < r ; j++)
	{
	  c[i][j] = 0;
	  for (int k = 0 ; k < n ; k++)
	  {
	    c[i][j] = a[i][k] * b[j][k];
	  }
	}
 
    }
}

int main()
{
  /*cout << "plz input m,n,r for m * n , n * r matrix." << endl;
  cout << " m = " ;
  cin >> m;
  cout << " n = ";
  cin >> n;
  cout << " r = ";
  cin >> r;*/
  int array1[m][n];
  int array2[n][r];
  for (int j = 0 ; j < n ; j++)
    {
      cout << "Type in " << m << " values for row " << j << " separated by spaces:" ;
      for (int i = 0 ; i < m ; i++)
	{
	  cin >> array1[j][i];
	} 
    } 
 for (int j = 0 ; j < r ; j++)
    {
      cout << "Type in " << m << " values for row " << j << " separated by spaces:" ;
      for (int i = 0 ; i < n ; i++)
	{
	  cin >> array2[j][i];
	} 
    }
 
 int array3[n][n];
 multiply_matrix(array1, array2, array3);

 cout << "the result: " << endl; 
 for (int i = 0; i < n ; i++)
   {
     for (int j = 0; j < n; j++)
       {
	 cout << array3[i][j] << " ";
       }
     cout << endl;
   }
}
