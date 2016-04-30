#include <stdio.h>
#include "pint.h"

static double power(int base, int e)
{
  if(e==1 || e==-1 || e==0)
    return base;
  return e<0? base/power(base,e+1) : base*power(base,e-1);
}

%%{
  machine pint;

  action mark {
    mark = p;
  }

  action key_parsed {
    int len = (p-mark);
  }

  action value_parsed {
    int len = (p-mark);
  }

  action integer_parsed {
    if(neg)
      val = -val;

    neg = 0;
    val = 0;
  }

  action float_parsed {
    // The significand is stored in val
    int e;
    char *z;
    
    e = p-radix_mark-1;

    float_val = (double)val / power(10,e);

    if(neg)
      float_val *= -1.0;

    neg = 0;
    val = 0;
  }

  action add_digit {
    val = val * 10 + (*p - '0');
  }

  float = ( (('+'|'-' @{neg = 1;}))? ([0-9] @add_digit)+ ('.' @{radix_mark=p;}) ([0-9] @add_digit)+ 'f'?) %float_parsed;
  integer = (('+'|('-' @{neg = 1;}))? ([0-9] @add_digit)+) %integer_parsed;
  string = [a-zA-Z0-9 -_.]+;

  key = string >mark %key_parsed;
  value = (float | integer | string) >mark %value_parsed;

  pair = key ':' value;
  message = pair;

  main := message (space message)* 0;
}%%

%% write data;

int pint_parse(char *data, pint_length_t length)
{
  int cs, res = 0;
  char *p = data;
  char *pe = data + length;
  char *eof = pe;

  char *mark;
  char *radix_mark;

  int64_t val = 0;
  double float_val = 0;
  int neg = 0;

  %% write init;
  %% write exec;

  return 0;
}
