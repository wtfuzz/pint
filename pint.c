
#line 1 "pint.rl"
#include <stdio.h>
#include "pint.h"

static double power(int base, int e)
{
  if(e==1 || e==-1 || e==0)
    return base;
  return e<0? base/power(base,e+1) : base*power(base,e-1);
}


#line 65 "pint.rl"



#line 19 "pint.c"
static const unsigned char _pint_key_offsets[] = {
	0, 0, 4, 9, 20, 29, 33, 38, 
	49, 58, 67, 82, 95, 109, 122, 136, 
	145, 154, 169, 182, 196, 209, 223, 232
};

static const char _pint_trans_keys[] = {
	32, 95, 97, 122, 58, 32, 95, 97, 
	122, 43, 45, 58, 32, 47, 48, 57, 
	59, 95, 97, 122, 0, 32, 58, 9, 
	13, 33, 95, 97, 122, 32, 95, 97, 
	122, 58, 32, 95, 97, 122, 43, 45, 
	58, 32, 47, 48, 57, 59, 95, 97, 
	122, 0, 32, 58, 9, 13, 33, 95, 
	97, 122, 0, 32, 58, 9, 13, 33, 
	95, 97, 122, 0, 32, 43, 45, 58, 
	9, 13, 33, 47, 48, 57, 59, 95, 
	97, 122, 0, 32, 58, 9, 13, 33, 
	47, 48, 57, 59, 95, 97, 122, 0, 
	32, 46, 58, 9, 13, 33, 47, 48, 
	57, 59, 95, 97, 122, 0, 32, 58, 
	9, 13, 33, 47, 48, 57, 59, 95, 
	97, 122, 0, 32, 58, 102, 9, 13, 
	33, 47, 48, 57, 59, 95, 97, 122, 
	0, 32, 58, 9, 13, 33, 95, 97, 
	122, 0, 32, 58, 9, 13, 33, 95, 
	97, 122, 0, 32, 43, 45, 58, 9, 
	13, 33, 47, 48, 57, 59, 95, 97, 
	122, 0, 32, 58, 9, 13, 33, 47, 
	48, 57, 59, 95, 97, 122, 0, 32, 
	46, 58, 9, 13, 33, 47, 48, 57, 
	59, 95, 97, 122, 0, 32, 58, 9, 
	13, 33, 47, 48, 57, 59, 95, 97, 
	122, 0, 32, 58, 102, 9, 13, 33, 
	47, 48, 57, 59, 95, 97, 122, 0, 
	32, 58, 9, 13, 33, 95, 97, 122, 
	0
};

static const char _pint_single_lengths[] = {
	0, 0, 1, 3, 3, 0, 1, 3, 
	3, 3, 5, 3, 4, 3, 4, 3, 
	3, 5, 3, 4, 3, 4, 3, 0
};

static const char _pint_range_lengths[] = {
	0, 2, 2, 4, 3, 2, 2, 4, 
	3, 3, 5, 5, 5, 5, 5, 3, 
	3, 5, 5, 5, 5, 5, 3, 0
};

static const unsigned char _pint_index_offsets[] = {
	0, 0, 3, 7, 15, 22, 25, 29, 
	37, 44, 51, 62, 71, 81, 90, 100, 
	107, 114, 125, 134, 144, 153, 163, 170
};

static const char _pint_indicies[] = {
	0, 0, 1, 3, 2, 2, 1, 5, 
	6, 8, 4, 7, 4, 4, 1, 9, 
	11, 13, 10, 12, 12, 1, 14, 14, 
	1, 16, 15, 15, 1, 18, 19, 21, 
	17, 20, 17, 17, 1, 9, 22, 24, 
	10, 23, 23, 1, 9, 25, 26, 10, 
	17, 17, 1, 9, 25, 18, 19, 21, 
	10, 17, 20, 17, 17, 1, 9, 22, 
	24, 10, 23, 27, 23, 23, 1, 28, 
	30, 31, 24, 29, 23, 27, 23, 23, 
	1, 9, 22, 24, 10, 23, 32, 23, 
	23, 1, 33, 35, 24, 36, 34, 23, 
	32, 23, 23, 1, 33, 35, 24, 34, 
	23, 23, 1, 9, 37, 8, 10, 4, 
	4, 1, 9, 38, 5, 6, 8, 10, 
	4, 7, 4, 4, 1, 9, 11, 13, 
	10, 12, 39, 12, 12, 1, 28, 40, 
	41, 13, 29, 12, 39, 12, 12, 1, 
	9, 11, 13, 10, 12, 42, 12, 12, 
	1, 33, 43, 13, 44, 34, 12, 42, 
	12, 12, 1, 33, 43, 13, 34, 12, 
	12, 1, 1, 0
};

static const char _pint_trans_targs[] = {
	2, 0, 2, 3, 4, 18, 18, 19, 
	17, 23, 5, 16, 4, 17, 6, 6, 
	7, 8, 11, 11, 12, 10, 9, 8, 
	10, 9, 10, 12, 23, 5, 9, 13, 
	14, 23, 5, 9, 15, 16, 16, 19, 
	16, 20, 21, 16, 22
};

static const char _pint_trans_actions[] = {
	1, 0, 0, 2, 1, 1, 3, 4, 
	5, 6, 6, 6, 0, 2, 1, 0, 
	2, 1, 1, 3, 4, 5, 6, 0, 
	2, 7, 8, 9, 10, 10, 10, 11, 
	9, 12, 12, 12, 0, 13, 7, 9, 
	10, 11, 9, 12, 0
};

static const int pint_start = 1;
static const int pint_first_final = 23;
static const int pint_error = 0;

static const int pint_en_main = 1;


#line 68 "pint.rl"

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

  
#line 144 "pint.c"
	{
	cs = pint_start;
	}

#line 84 "pint.rl"
  
#line 151 "pint.c"
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
    int len = (p-mark);
  }
	break;
	case 6:
#line 22 "pint.rl"
	{
    int len = (p-mark);
  }
	break;
	case 9:
#line 50 "pint.rl"
	{
    val = val * 10 + (*p - '0');
  }
	break;
	case 11:
#line 54 "pint.rl"
	{radix_mark=p;}
	break;
	case 8:
#line 14 "pint.rl"
	{
    mark = p;
  }
#line 18 "pint.rl"
	{
    int len = (p-mark);
  }
	break;
	case 7:
#line 14 "pint.rl"
	{
    mark = p;
  }
#line 22 "pint.rl"
	{
    int len = (p-mark);
  }
	break;
	case 4:
#line 14 "pint.rl"
	{
    mark = p;
  }
#line 50 "pint.rl"
	{
    val = val * 10 + (*p - '0');
  }
	break;
	case 5:
#line 18 "pint.rl"
	{
    int len = (p-mark);
  }
#line 14 "pint.rl"
	{
    mark = p;
  }
	break;
	case 13:
#line 22 "pint.rl"
	{
    int len = (p-mark);
  }
#line 14 "pint.rl"
	{
    mark = p;
  }
	break;
	case 10:
#line 26 "pint.rl"
	{
    if(neg)
      val = -val;

    neg = 0;
    val = 0;
  }
#line 22 "pint.rl"
	{
    int len = (p-mark);
  }
	break;
	case 12:
#line 34 "pint.rl"
	{
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
#line 22 "pint.rl"
	{
    int len = (p-mark);
  }
	break;
	case 3:
#line 14 "pint.rl"
	{
    mark = p;
  }
#line 54 "pint.rl"
	{neg = 1;}
#line 55 "pint.rl"
	{neg = 1;}
	break;
#line 342 "pint.c"
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 85 "pint.rl"

  return 0;
}
