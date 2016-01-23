#ifndef CSIPHASH_SIPHASH_H
#define CSIPHASH_SIPHASH_H

#include <inttypes.h>

extern uint64_t siphash(char key[16], char data[], int c, int d);

#endif
