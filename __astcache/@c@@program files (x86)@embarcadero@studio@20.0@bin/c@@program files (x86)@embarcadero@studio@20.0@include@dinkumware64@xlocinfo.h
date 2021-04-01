/* xlocinfo.h internal header for gcc Linux */
#ifndef _XLOCINFO
#define _XLOCINFO
#include <locale.h>
#include <yvals.h>
_C_STD_BEGIN
_C_LIB_DECL

		/* CTYPE CODE BITS */
#ifndef _XB
 #define _XB	0x400 /* extra blank */
 #define _XA	0x200 /* extra alphabetic */
 #define _XS	0x100 /* extra space */
 #define _BB	0x80 /* BEL, BS, etc. */
 #define _CN	0x40 /* CR, FF, HT, NL, VT */
 #define _DI	0x20 /* '0'-'9' */
 #define _LO	0x10 /* 'a'-'z' */
 #define _PU	0x08 /* punctuation */
 #define _SP	0x04 /* space */
 #define _UP	0x02 /* 'A'-'Z' */
 #define _XD	0x01 /* '0'-'9', 'A'-'F', 'a'-'f' */
#endif /* _XB */

		/* SUPPLEMENTAL LOCALE MACROS AND DECLARATIONS */

 #if _IS_GHS
  #define _X_COLLATE	0
  #define _X_CTYPE		1
  #define _X_MONETARY	2
  #define _X_NUMERIC	3
  #define _X_TIME 		4
  #define _X_MESSAGES	5
  #define _X_MAX		_X_MESSAGES	/* highest real category */
  #define _CAT_TO_LC(cat)	_CATMASK(cat)

 #if defined(_MC_EXEC)
#undef _NCAT
 #endif /* defined(_MC_EXEC) */

#ifndef _NCAT
 #define _NCAT			(_X_MESSAGES + 1)	/* maximum + 1 */
 #define _CATMASK(n)	\
	(1 << ((n) - (_X_COLLATE < _X_CTYPE ? _X_COLLATE : _X_CTYPE)))

 #define _M_COLLATE		_CATMASK(_X_COLLATE)
 #define _M_CTYPE		_CATMASK(_X_CTYPE)
 #define _M_MONETARY	_CATMASK(_X_MONETARY)
 #define _M_NUMERIC		_CATMASK(_X_NUMERIC)
 #define _M_TIME		_CATMASK(_X_TIME)
 #define _M_MESSAGES	_CATMASK(_X_MESSAGES)
 #define _M_ALL			(_CATMASK(_NCAT) - 1)
#endif /* _NCAT */

		/* FUNCTION DECLARATIONS */
const short *_Getctyptab();

 #if !(defined(__ghs) || defined(__SC3__)) || !defined(__NoFloat)
extern float _Stof(const char *, char **, long);

  #if defined(__ghs) && defined(_MC_EXEC)
#define _Stod(a,b,c)  _mc_Stod(a,b,c)
  #endif /* defined(__ghs), etc. */

 #if defined(__ghs) && defined(__ADSPBLACKFIN__)
#define _Stod  _ghs_Stod
 #endif /* defined__ghs), etc. */

 #if !defined(__ghs__) || !defined(__FloatSingle__)
extern double _Stod(const char *, char **, long);
extern long double _Stold(const char *, char **, long);
 #endif /* !defined(__ghs__), etc. */

#endif /* !defined(__ghs), etc. */

 #else /* _IS_GHS */

 #if defined(__BORLANDC__)
  #define _X_COLLATE	0
  #define _X_CTYPE		1
  #define _X_MONETARY	2
  #define _X_NUMERIC	3
  #define _X_TIME 		4
  #define _X_MESSAGES	5
  #define _X_MAX		_X_MESSAGES	/* highest real category */
  #define _CAT_TO_LC(cat)	_CATMASK(cat)

 #else	/* defined(__BORLANDC__) etc. */
  #define _X_COLLATE	LC_COLLATE
  #define _X_CTYPE		LC_CTYPE
  #define _X_MONETARY	LC_MONETARY
  #define _X_NUMERIC	LC_NUMERIC
  #define _X_TIME 		LC_TIME
  #define _X_MESSAGES	LC_MESSAGES
  #define _X_MAX		_X_MESSAGES	/* highest real category */
#endif /* defined(_BORLANDC_) etc. */

#ifndef _NCAT
 #define _NCAT			(_X_MESSAGES + 1)	/* maximum + 1 */

 #if defined(__GLIBC__) && !defined(__APPLE__)
  #define _CATMASK(n)	(1 << (n))

 #else /* defined(__GLIBC__) etc. */
  #define _CATMASK(n)	\
	(1 << ((n) - (_X_COLLATE < _X_CTYPE ? _X_COLLATE : _X_CTYPE)))
 #endif /* defined(__GLIBC__) etc. */

 #define _M_COLLATE		_CATMASK(_X_COLLATE)
 #define _M_CTYPE		_CATMASK(_X_CTYPE)
 #define _M_MONETARY	_CATMASK(_X_MONETARY)
 #define _M_NUMERIC		_CATMASK(_X_NUMERIC)
 #define _M_TIME		_CATMASK(_X_TIME)
 #define _M_MESSAGES	_CATMASK(_X_MESSAGES)
 #define _M_ALL			(_CATMASK(_NCAT) - 1)
#endif /* _NCAT */

#if defined(__CODEGEARC__)
typedef struct _Collvec
	{	/* stuff needed by _Strcoll, etc. */
	unsigned long _Hand;	// LCID
	unsigned int _Page;	// UINT
	} _Collvec;

typedef struct _Ctypevec
	{	/* stuff needed by _Tolower, etc. */
	unsigned long _Hand;	// LCID
	unsigned int _Page;	// UINT
	const short *_Table;
	int _Delfl;
	} _Ctypevec;

typedef struct _Cvtvec
	{	/* stuff needed by _Mbrtowc, etc. */
	unsigned long _Hand;	// LCID
	unsigned int _Page;	// UINT
	} _Cvtvec;
#endif
		/* FUNCTION DECLARATIONS */
const short *_Getctyptab();
extern float _Stof(const char *, char **, long);
extern double _Stod(const char *, char **, long);
extern long double _Stold(const char *, char **, long);
 #endif /* _IS_GHS */

_END_C_LIB_DECL
_C_STD_END
#endif /* _XLOCINFO */

/*
 * Copyright (c) by P.J. Plauger. All rights reserved.
 * Consult your license regarding permissions and restrictions.
V8.03a/17:1422 */
