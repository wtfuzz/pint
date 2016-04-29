#include <stdio.h>
#include <stdlib.h>

#include "pint.h"

int main()
{
  char buf[] = "foo";
  pint_parse(buf, sizeof(buf));
}
