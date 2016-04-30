#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "pint.h"

void object_callback(char *key, uint8_t key_length, pint_object_t *obj)
{
  printf("Object [%.*s] Type %d Value: ", key_length, key, obj->type);

  switch(obj->type)
  {
    case PINT_TYPE_FLOAT:
      printf("%f", obj->f);
      break;
    case PINT_TYPE_S32:
      printf("%" PRIi32, obj->s32);
      break;
    case PINT_TYPE_STRING:
      printf("%.*s", obj->length, obj->string);
      break;
    default:
      printf("???");
      break;
  }

  printf("\n");
}

int main()
{
  char float_test[] = "foo:-1.1237";
  char float_test2[] = "foo:345.343488";
  char float_test3[] = "foo:345.3434880000";
  char int_test[] = "foo:84757";
  char int_test2[] = "steer:-10 accel:20";
  char list_test[] = "list:1,2,3,4,5 timer:555";
  char string_test[] = "str:hello_world";
  pint_parse(float_test, sizeof(float_test), object_callback);
  pint_parse(float_test2, sizeof(float_test2), object_callback);
  pint_parse(float_test3, sizeof(float_test3), object_callback);
  pint_parse(int_test, sizeof(int_test), object_callback);
  pint_parse(int_test2, sizeof(int_test2), object_callback);
  pint_parse(list_test, sizeof(list_test), object_callback);
  pint_parse(string_test, sizeof(string_test), object_callback);
}
