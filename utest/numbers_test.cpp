#ifdef __cplusplus
extern "C" {
#endif
	/* if not included as ANSI C code it won't compile */
	#include "numbers.h"

#ifdef __cplusplus
}
#endif

#include "math_mock.h"

#include <gtest/gtest.h>

using namespace testing;

TEST(numbers_test, even_value)
{
	is_even_mock iem;
	EXPECT_FUNCTION_CALL(iem, (_)).WillOnce(Return(false));

	EXPECT_TRUE(is_odd(3));
}

