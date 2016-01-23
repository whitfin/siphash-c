#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../src/siphash.h"

#define test(expected, key, input, c, d)        		\
	do {																							\
		uint64_t output = siphash(key, input, c, d);		\
  	assert(expected == output);                  		\
	} while(0);


int main () {
		test(4402678656023170274, "0123456789ABCDEF", "hello", 2, 4);			/* test default hash */
		test(4402678656023170274, "0123456789ABCDEFF", "hello", 2, 4); 		/* extra byte ignored */
		test(14986662229302055855UL, "0123456789ABCDEF", "hello", 4, 8);	/* check compression changes */
		return 0;
}
