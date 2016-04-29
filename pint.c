
#line 1 "pint.rl"
#include <stdio.h>
#include "pint.h"


#line 15 "pint.rl"



#line 12 "pint.c"
static const char _pint_actions[] = {
	0, 1, 0
};

static const char _pint_key_offsets[] = {
	0, 0, 1, 2, 3, 4
};

static const char _pint_trans_keys[] = {
	102, 111, 111, 0, 0
};

static const char _pint_single_lengths[] = {
	0, 1, 1, 1, 1, 0
};

static const char _pint_range_lengths[] = {
	0, 0, 0, 0, 0, 0
};

static const char _pint_index_offsets[] = {
	0, 0, 2, 4, 6, 8
};

static const char _pint_trans_targs[] = {
	2, 0, 3, 0, 4, 0, 5, 0, 
	0, 0
};

static const char _pint_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0
};

static const int pint_start = 1;
static const int pint_first_final = 5;
static const int pint_error = 0;

static const int pint_en_main = 1;


#line 18 "pint.rl"

int pint_parse(char *data, pint_length_t length)
{
  int cs, res = 0;
  char *p = data;
  char *pe = data + length;
  char *eof = pe;

  pint_message_t msg;
  
  
#line 66 "pint.c"
	{
	cs = pint_start;
	}

#line 29 "pint.rl"
  
#line 73 "pint.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

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
	cs = _pint_trans_targs[_trans];

	if ( _pint_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _pint_actions + _pint_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 7 "pint.rl"
	{
    printf("Header\n");
  }
	break;
#line 152 "pint.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 30 "pint.rl"

  return 0;
}
