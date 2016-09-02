/* APPLE LOCAL file v7 merge */
/* Test the `vsubhns64' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vsubhns64 (void)
{
  int32x2_t out_int32x2_t;
  int64x2_t arg0_int64x2_t;
  int64x2_t arg1_int64x2_t;

  out_int32x2_t = vsubhn_s64 (arg0_int64x2_t, arg1_int64x2_t);
}

/* { dg-final { scan-assembler "vsubhn\.i64\[ 	\]+\[dD\]\[0-9\]+, \[qQ\]\[0-9\]+, \[qQ\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
