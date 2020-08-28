#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int out_square(int in)
{
  int res = 0;
  while (in != 0)
  {
    res += pow(in % 10, 2);
    in /= 10;
  }
  return res;
}

int squareDigitsSequence(int a0)
{
  int count = 1;
  int a_in = a0;
  int buf[40] = {0};
  int buf_idx = 1;
  buf[0] = a0;
  if (a0 == 1)
  {
    return 2;
  }
  while (true)
  {
    a_in = out_square(a_in);
    printf("out: %d\n", a_in);
    /* Checking in list */
    for (int i = 0; i < buf_idx; i++)
    {
      if (buf[i] == a_in)
      {
        count++;
        goto out;
      }
    }
    buf[buf_idx++] = a_in;
    count++;
  }
out:
  printf("count is: %d", count);
  return count;
}

int main(int argc, char **argv)
{
  (void)squareDigitsSequence(16);
  return 0;
}