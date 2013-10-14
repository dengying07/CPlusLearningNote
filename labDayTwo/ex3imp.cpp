#include <iostream>
#include "ex3.h"
using namespace std;
double average(int a_number, double *a_digit)
{
  double a_average = 0;
  for(int i=0 ; i < a_number; i++)
    {
      a_average +=  *a_digit++;
    }
  a_average /= a_number;
  return a_average;
}
double standard_deviation(int s_number, double *s_digit)
{
  double s_average = average(s_number, s_digit);
  double s_sdeviation = 0;
  for(int i=0; i < s_number; i++)
    {
      s_sdeviation += ((*s_digit) - s_average)*((*s_digit) - s_average);
      s_digit++;
    }
  s_sdeviation /= s_number;
  return s_sdeviation;
}
