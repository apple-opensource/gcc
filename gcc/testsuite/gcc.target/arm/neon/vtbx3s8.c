/* APPLE LOCAL file v7 merge */
/* Test the `vtbx3s8' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vtbx3s8 (void)
{
  int8x8_t out_int8x8_t;
  int8x8_t arg0_int8x8_t;
  int8x8x3_t arg1_int8x8x3_t;
  int8x8_t arg2_int8x8_t;

  out_int8x8_t = vtbx3_s8 (arg0_int8x8_t, arg1_int8x8x3_t, arg2_int8x8_t);
}

/* { dg-final { scan-assembler "vtbx\.8\[ 	\]+\[dD\]\[0-9\]+, \\\{((\[dD\]\[0-9\]+-\[dD\]\[0-9\]+)|(\[dD\]\[0-9\]+, \[dD\]\[0-9\]+, \[dD\]\[0-9\]+))\\\}, \[dD\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
