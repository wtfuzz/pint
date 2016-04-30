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
    key_string = mark;
    key_length = (p-mark);
  }

  action value_start {
    obj.type = PINT_TYPE_NULL;
    mark = p;
    neg = 0;
    val = 0;
  }

  action value_parsed {
    int len = (p-mark);

    if(cb)
    {
      (*cb)(key_string, key_length, &obj);
    }

    obj.type = PINT_TYPE_NULL;
  }

  action integer_parsed {
    if(neg)
      val = -val;

    obj.type = PINT_TYPE_S32;
    obj.s32 = val;

    neg = 0;
    val = 0;
  }

  action float_parsed {
    // The significand is stored in val
    int e;
    
    e = p-radix_mark-1;

    float_val = (float)val / power(10,e);

    if(neg)
      float_val *= -1.0;

    obj.type = PINT_TYPE_FLOAT;
    obj.f = float_val;

    neg = 0;
    val = 0;
  }

  action string_parsed {

    if(obj.type == PINT_TYPE_NULL)
    {
      obj.type = PINT_TYPE_STRING;
      obj.string = mark;
      obj.length = p-mark; 
    }
  }

  action add_digit {
    val = val * 10 + (*p - '0');
  }

  float = ( (('+'|'-' @{neg = 1;}))? ([0-9] @add_digit)+ ('.' @{radix_mark=p;}) ([0-9] @add_digit)+ 'f'?) %float_parsed;
  integer = (('+'|('-' @{neg = 1;}))? ([0-9] @add_digit)+) %integer_parsed;
  string = ([a-zA-Z0-9 \-_.]+) >mark %string_parsed;
  boolean = ('true'|'t'|'false'|'f');

  key = [a-zA-Z0\-9-_.]+ >mark %key_parsed;
  value = (string | float | integer | boolean) >value_start %value_parsed;

  pair = key ':' value (',' value)*;
  #pair = key ':' value;
  message = pair;

  main := message (space message)* 0;
}%%

%% write data;

int pint_parse(char *data, pint_length_t length, pint_callback_t cb)
{
  int cs, res = 0;
  char *p = data;
  char *pe = data + length;
  char *eof = pe;

  char *mark;
  char *radix_mark;

  char *key_string;
  uint8_t key_length;
 
  pint_object_t obj;

  int64_t val = 0;
  double float_val = 0;
  int neg = 0;

  %% write init;
  %% write exec;

  res = cs >= pint_first_final;

  if(res == 0)
  {
    printf("Failed at %s\n", p);
  } 

  return 0;
}
