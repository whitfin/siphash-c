#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../src/siphash.h"

#define test(expected, key, input, c, d, length)        	\
	do {																							\
		uint64_t output = siphash(key, input, c, d, length);		\
  	assert(expected == output);                  		\
	} while(0);


int main () {
		char* test_string = "hello";
		size_t test_string_length = strlen(test_string);

		test(4402678656023170274, "0123456789ABCDEF", test_string, 2, 4, test_string_length);			/* test default hash */
		test(4402678656023170274, "0123456789ABCDEFF", test_string, 2, 4, test_string_length); 		/* extra byte ignored */
		test(14986662229302055855UL, "0123456789ABCDEF", test_string, 4, 8, test_string_length);	/* check compression changes */
		return 0;
}
