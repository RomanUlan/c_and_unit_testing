#ifndef MATH_MOCK_H
#define MATH_MOCK_H

#ifdef __cplusplus
extern "C" {
#endif
	/* if not included as ANSI C code the mock will be never called */
	#include "math.h"

#ifdef __cplusplus
}
#endif


#include "cmock/cmock.h"

DECLARE_FUNCTION_MOCK1(is_even_mock, is_even, bool(int));

#endif

