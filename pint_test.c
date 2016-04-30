#include <stdio.h>
#include <stdlib.h>

#include "pint.h"

int main()
{
  char float_test[] = "foo:-1.1237";
  char float_test2[] = "foo:345.343488";
  char float_test3[] = "foo:345.3434880000";
  char int_test[] = "foo:84757";
  char int_test2[] = "steer:-10 accel:20";
  pint_parse(float_test, sizeof(float_test));
  pint_parse(float_test2, sizeof(float_test2));
  pint_parse(float_test3, sizeof(float_test3));
  pint_parse(int_test, sizeof(int_test));
  pint_parse(int_test2, sizeof(int_test2));
}
