#include <stdio.h>
#include "pint.h"

%%{
  machine pint;

  action header {
    printf("Header\n");
  }

  header = 'foo' %header;

  main := header 0;
}%%

%% write data;

int pint_parse(char *data, pint_length_t length)
{
  int cs, res = 0;
  char *p = data;
  char *pe = data + length;
  char *eof = pe;

  pint_message_t msg;
  
  %% write init;
  %% write exec;

  return 0;
}
