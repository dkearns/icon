/*
 *  infer.c -- generate definitions reflecting present hardware architecture
 *
 *  Inspired by mail from Christian Hudon.
 */

#include <assert.h>
#include <stddef.h>
#include <stdio.h>

typedef struct {
   char c;
   double d;
   } tstruct;

#pragma GCC diagnostic ignored "-Wreturn-stack-address"
static long atdepth(int n) {
   return n <= 1 ? (long)&n : atdepth(n - 1);
   }

int main(int argc, char *argv[]) {
   assert (-1 == (signed char)0xFF);		/* chars must be 8 bits */
   assert (sizeof(void*) == sizeof(long));	/* these must be the same */
   assert (sizeof(int) >= 4);			/* need 32-bit ints or better */
   assert (sizeof(long) <= 8);			/* but can't handle over 64 */
   printf("/* generated by infer.c */\n");
   printf("#define IntBits %d\n", (int) (8 * sizeof(int)));
   printf("#define WordBits %d\n", (int) (8 * sizeof(void *)));
   if (offsetof(tstruct, d) > sizeof(void *))
      printf("#define Double\n");
   if (atdepth(2) > atdepth(1))
      printf("#define UpStack\n");
   return 0;
   }
