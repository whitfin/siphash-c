#ifndef CSIPHASH_SIPHASH_H
#define CSIPHASH_SIPHASH_H

#include <inttypes.h>

extern uint64_t siphash(const char key[16], const char data[], unsigned int c, unsigned int d, size_t data_len);

#endif
