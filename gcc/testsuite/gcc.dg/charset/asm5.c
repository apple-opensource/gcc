/* Test for string translation.  */
/* { dg-do compile }
   { dg-require-iconv "IBM-1047" }
   { dg-final { scan-assembler-not "translate" } } */
void foo (void)
{
  asm ("xx" : : "r"("translate") : "cc");
}
