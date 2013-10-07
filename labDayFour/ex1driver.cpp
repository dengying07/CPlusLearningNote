#include "ex1.h"
#include <iostream>
bool test_num(int num)
{
  int ret = 1;
  for (int i = 2 ; i <= 32 ; i++)
    {
      if((num % i) == 0 && num > i)
	{
	  std::cout << i << " " << num << " " << num%i << std::endl;
	  ret = 0;
	  break;
	}
    }
  return ret;
}
