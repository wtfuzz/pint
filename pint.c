
#line 1 "pint.rl"
#include <stdio.h>
#include "pint.h"

static double power(int base, int e)
{
  if(e==1 || e==-1 || e==0)
    return base;
  return e<0? base/power(base,e+1) : base*power(base,e-1);
}


#line 97 "pint.rl"



#line 19 "pint.c"
static const short _pint_key_offsets[] = {
	0, 0, 7, 15, 33, 47, 67, 78, 
	80, 88, 90, 98, 103, 117, 131, 145, 
	160, 174, 195, 216, 237, 258, 280, 301
};

static const char _pint_trans_keys[] = {
	48, 45, 46, 57, 95, 97, 122, 48, 
	58, 45, 46, 57, 95, 97, 122, 32, 
	43, 45, 46, 48, 57, 58, 95, 49, 
	56, 59, 64, 65, 90, 91, 94, 97, 
	122, 0, 32, 44, 95, 9, 13, 45, 
	46, 48, 57, 65, 90, 97, 122, 0, 
	32, 44, 48, 57, 95, 9, 13, 45, 
	46, 49, 56, 58, 64, 65, 90, 91, 
	94, 97, 122, 32, 43, 45, 46, 95, 
	48, 57, 65, 90, 97, 122, 48, 57, 
	0, 32, 44, 46, 9, 13, 48, 57, 
	48, 57, 0, 32, 44, 102, 9, 13, 
	48, 57, 0, 32, 44, 9, 13, 0, 
	32, 44, 95, 9, 13, 45, 46, 48, 
	57, 65, 90, 97, 122, 0, 32, 44, 
	45, 46, 95, 9, 13, 48, 57, 65, 
	90, 97, 122, 0, 32, 44, 95, 9, 
	13, 45, 46, 48, 57, 65, 90, 97, 
	122, 0, 32, 44, 95, 102, 9, 13, 
	45, 46, 48, 57, 65, 90, 97, 122, 
	0, 32, 44, 95, 9, 13, 45, 46, 
	48, 57, 65, 90, 97, 122, 0, 32, 
	44, 48, 57, 58, 95, 9, 13, 45, 
	46, 49, 56, 59, 64, 65, 90, 91, 
	94, 97, 122, 0, 32, 44, 48, 57, 
	58, 95, 9, 13, 45, 46, 49, 56, 
	59, 64, 65, 90, 91, 94, 97, 122, 
	0, 32, 44, 45, 46, 48, 57, 58, 
	95, 9, 13, 49, 56, 59, 64, 65, 
	90, 91, 94, 97, 122, 0, 32, 44, 
	48, 57, 58, 95, 9, 13, 45, 46, 
	49, 56, 59, 64, 65, 90, 91, 94, 
	97, 122, 0, 32, 44, 48, 57, 58, 
	95, 102, 9, 13, 45, 46, 49, 56, 
	59, 64, 65, 90, 91, 94, 97, 122, 
	0, 32, 44, 48, 57, 58, 95, 9, 
	13, 45, 46, 49, 56, 59, 64, 65, 
	90, 91, 94, 97, 122, 0
};

static const char _pint_single_lengths[] = {
	0, 1, 2, 8, 4, 6, 5, 0, 
	4, 0, 4, 3, 4, 6, 4, 5, 
	4, 7, 7, 9, 7, 8, 7, 0
};

static const char _pint_range_lengths[] = {
	0, 3, 3, 5, 5, 7, 3, 1, 
	2, 1, 2, 1, 5, 4, 5, 5, 
	5, 7, 7, 6, 7, 7, 7, 0
};

static const unsigned char _pint_index_offsets[] = {
	0, 0, 5, 11, 25, 35, 49, 58, 
	60, 67, 69, 76, 81, 91, 102, 112, 
	123, 133, 148, 163, 179, 194, 210, 225
};

static const char _pint_indicies[] = {
	0, 0, 0, 0, 1, 2, 3, 2, 
	2, 2, 1, 4, 5, 6, 7, 8, 
	8, 3, 7, 9, 2, 7, 2, 7, 
	1, 10, 12, 13, 14, 11, 14, 14, 
	14, 14, 1, 10, 12, 13, 15, 15, 
	15, 11, 15, 14, 0, 15, 0, 15, 
	1, 4, 5, 16, 4, 4, 9, 4, 
	4, 1, 17, 1, 18, 19, 20, 21, 
	19, 17, 1, 22, 1, 23, 24, 25, 
	26, 24, 22, 1, 23, 24, 25, 24, 
	1, 10, 12, 13, 14, 11, 14, 27, 
	14, 14, 1, 28, 30, 31, 14, 32, 
	14, 29, 27, 14, 14, 1, 10, 12, 
	13, 14, 11, 14, 33, 14, 14, 1, 
	34, 36, 37, 14, 38, 35, 14, 33, 
	14, 14, 1, 34, 36, 37, 14, 35, 
	14, 14, 14, 14, 1, 10, 12, 13, 
	39, 39, 3, 39, 11, 39, 14, 2, 
	39, 2, 39, 1, 10, 12, 13, 40, 
	40, 3, 39, 11, 39, 27, 2, 39, 
	2, 39, 1, 28, 30, 31, 39, 41, 
	40, 40, 3, 39, 29, 27, 2, 39, 
	2, 39, 1, 10, 12, 13, 42, 42, 
	3, 39, 11, 39, 33, 2, 39, 2, 
	39, 1, 34, 36, 37, 42, 42, 3, 
	39, 43, 35, 39, 33, 2, 39, 2, 
	39, 1, 34, 36, 37, 39, 39, 3, 
	39, 35, 39, 14, 2, 39, 2, 39, 
	1, 1, 0
};

static const char _pint_trans_targs[] = {
	2, 0, 2, 3, 4, 7, 18, 17, 
	19, 13, 23, 1, 5, 6, 4, 17, 
	12, 8, 23, 1, 6, 9, 10, 23, 
	1, 6, 11, 13, 23, 1, 5, 6, 
	14, 15, 23, 1, 5, 6, 16, 17, 
	19, 20, 21, 22
};

static const char _pint_trans_actions[] = {
	1, 0, 0, 2, 3, 4, 5, 3, 
	6, 6, 7, 7, 7, 7, 0, 1, 
	5, 8, 9, 9, 9, 10, 8, 11, 
	11, 11, 0, 8, 12, 12, 12, 12, 
	10, 8, 13, 13, 13, 13, 0, 0, 
	8, 10, 8, 0
};

static const int pint_start = 1;
static const int pint_first_final = 23;
static const int pint_error = 0;

static const int pint_en_main = 1;


#line 100 "pint.rl"

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

  
#line 164 "pint.c"
	{
	cs = pint_start;
	}

#line 121 "pint.rl"
  
#line 171 "pint.c"
	{
	int _klen;
	const char *_keys;
	int _trans;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _pint_trans_keys + _pint_key_offsets[cs];
	_trans = _pint_index_offsets[cs];

	_klen = _pint_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _pint_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _pint_indicies[_trans];
	cs = _pint_trans_targs[_trans];

	if ( _pint_trans_actions[_trans] == 0 )
		goto _again;

	switch ( _pint_trans_actions[_trans] ) {
	case 1:
#line 14 "pint.rl"
	{
    mark = p;
  }
	break;
	case 2:
#line 18 "pint.rl"
	{
    key_string = mark;
    key_length = (p-mark);
  }
	break;
	case 4:
#line 23 "pint.rl"
	{
    obj.type = PINT_TYPE_NULL;
    mark = p;
    neg = 0;
    val = 0;
  }
	break;
	case 8:
#line 80 "pint.rl"
	{
    val = val * 10 + (*p - '0');
  }
	break;
	case 10:
#line 84 "pint.rl"
	{radix_mark=p;}
	break;
	case 3:
#line 23 "pint.rl"
	{
    obj.type = PINT_TYPE_NULL;
    mark = p;
    neg = 0;
    val = 0;
  }
#line 14 "pint.rl"
	{
    mark = p;
  }
	break;
	case 9:
#line 41 "pint.rl"
	{
    if(neg)
      val = -val;

    obj.type = PINT_TYPE_S32;
    obj.s32 = val;

    neg = 0;
    val = 0;
  }
#line 30 "pint.rl"
	{
    int len = (p-mark);

    if(cb)
    {
      (*cb)(key_string, key_length, &obj);
    }

    obj.type = PINT_TYPE_NULL;
  }
	break;
	case 11:
#line 52 "pint.rl"
	{
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
#line 30 "pint.rl"
	{
    int len = (p-mark);

    if(cb)
    {
      (*cb)(key_string, key_length, &obj);
    }

    obj.type = PINT_TYPE_NULL;
  }
	break;
	case 7:
#line 70 "pint.rl"
	{

    if(obj.type == PINT_TYPE_NULL)
    {
      obj.type = PINT_TYPE_STRING;
      obj.string = mark;
      obj.length = p-mark; 
    }
  }
#line 30 "pint.rl"
	{
    int len = (p-mark);

    if(cb)
    {
      (*cb)(key_string, key_length, &obj);
    }

    obj.type = PINT_TYPE_NULL;
  }
	break;
	case 6:
#line 23 "pint.rl"
	{
    obj.type = PINT_TYPE_NULL;
    mark = p;
    neg = 0;
    val = 0;
  }
#line 14 "pint.rl"
	{
    mark = p;
  }
#line 80 "pint.rl"
	{
    val = val * 10 + (*p - '0');
  }
	break;
	case 12:
#line 70 "pint.rl"
	{

    if(obj.type == PINT_TYPE_NULL)
    {
      obj.type = PINT_TYPE_STRING;
      obj.string = mark;
      obj.length = p-mark; 
    }
  }
#line 41 "pint.rl"
	{
    if(neg)
      val = -val;

    obj.type = PINT_TYPE_S32;
    obj.s32 = val;

    neg = 0;
    val = 0;
  }
#line 30 "pint.rl"
	{
    int len = (p-mark);

    if(cb)
    {
      (*cb)(key_string, key_length, &obj);
    }

    obj.type = PINT_TYPE_NULL;
  }
	break;
	case 13:
#line 70 "pint.rl"
	{

    if(obj.type == PINT_TYPE_NULL)
    {
      obj.type = PINT_TYPE_STRING;
      obj.string = mark;
      obj.length = p-mark; 
    }
  }
#line 52 "pint.rl"
	{
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
#line 30 "pint.rl"
	{
    int len = (p-mark);

    if(cb)
    {
      (*cb)(key_string, key_length, &obj);
    }

    obj.type = PINT_TYPE_NULL;
  }
	break;
	case 5:
#line 23 "pint.rl"
	{
    obj.type = PINT_TYPE_NULL;
    mark = p;
    neg = 0;
    val = 0;
  }
#line 14 "pint.rl"
	{
    mark = p;
  }
#line 84 "pint.rl"
	{neg = 1;}
#line 85 "pint.rl"
	{neg = 1;}
	break;
#line 470 "pint.c"
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 122 "pint.rl"

  res = cs >= pint_first_final;

  if(res == 0)
  {
    printf("Failed at %s\n", p);
  } 

  return 0;
}
