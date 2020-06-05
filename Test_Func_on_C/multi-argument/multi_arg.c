#include "call_libs.h"

double average_cal(int num, ...)
{
  va_list valist;
  double sum = 0.0;
  int i;

  /* Initialize valist for num number of arguments*/
  va_start(valist, num);

  /* Get data type */
  int type = va_arg(valist, int);

  /* Access all the arguments assigned to valist */
  if (type == 0) // INT type
  {
    for (i = 1; i < num; i++)
    {
      sum += va_arg(valist, int);
    }
  }
  else
  {
    for (i = 1; i < num; i++)
    {
      sum += va_arg(valist, double);
    }
  }

  /* Clean memory reserved for valist */
  va_end(valist);

  return sum/(num - 1);
}

void test_multi_arg()
{
  printf("For int arg:\n");
  printf("Average of 3,4,5 = %f\n", average_cal(4,0,3,4,5));
  printf("Average of 3,4,5,6 = %f\n", average_cal(5,0,3,4,5,6));

  printf("For float arg:\n");
  printf("Average of 2.2, 3.3: %f\n",average_cal(3,1,2.2,3.3 ));
  printf("Average of 2.2, 3.3, 4.4: %f\n",average_cal(4,1,2.2,3.3,4.4));
}
