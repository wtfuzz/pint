#ifndef PINT_H_
#define PINT_H_

#include <inttypes.h>

typedef uint16_t pint_length_t;

typedef enum _pint_type_t
{
  PINT_TYPE_STRING,
  PINT_TYPE_BINARY,
  PINT_TYPE_FLOAT,
  PINT_TYPE_DOUBLE,
  PINT_TYPE_S8,
  PINT_TYPE_S16,
  PINT_TYPE_S32,
  PINT_TYPE_S64,
  PINT_TYPE_U8,
  PINT_TYPE_U16,
  PINT_TYPE_U32,
  PINT_TYPE_U64,
} pint_type_t;

/** @brief Pint Data Object container */
typedef struct _pint_object_t
{
  pint_length_t length;
  pint_type_t type; 

  union {
    char *string;
    uint8_t *binary;
    float *f;
    double *d;
    int8_t *s8;
    int16_t *s16;
    int32_t *s32;
    int64_t *s64;
    uint8_t *u8;
    uint16_t *u16;
    uint32_t *u32;
    uint64_t *u64;
  };
} pint_object_t;

/** @brief A single key:value pair */
typedef struct _pint_pair_t
{
  pint_object_t key;
  pint_object_t value;
} pint_pair_t;

/** @brief Pint Message context */
typedef struct _pint_message_t
{
  /** @brief Number of keys contained in this message */
  pint_length_t value_count;
} pint_message_t;

int pint_parse(char *, pint_length_t);

#endif
