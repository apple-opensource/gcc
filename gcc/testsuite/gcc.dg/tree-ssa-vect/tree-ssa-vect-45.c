/* APPLE LOCAL file -haifa  */
/* { dg-do run { target powerpc*-*-* } } */
/* { dg-options "-O2 -ftree-vectorize -fdump-tree-vect-stats -maltivec" { target powerpc*-*-* } } */
/* { dg-options "-O2 -ftree-vectorize -fdump-tree-vect-stats -msse" { target i?86-*-* } } */
  
#include <stdarg.h>
#include <signal.h>

#define N 256

typedef float afloat __attribute__ ((__aligned__(16)));

void bar (const float *pa, const float *pb, const float *pc) 
{
  int i;

  /* check results:  */
  for (i = 0; i < N; i++)
    {
      if (pa[i] != (pb[i] * pc[i]))
        printf("%f * %f != %f\n",pb[i],pc[i],pa[i]);
    }

  return;
}


int
main1 (float *pa, float *pb, float *pc)
{
  int i;

  for (i = 0; i < N; i++)
    {
      pa[i] = pb[i] * pc[i];
    }

  bar (pa,pb,pc);

  return 0;
}

void
sig_ill_handler (int sig)
{
    exit(0);
}

int main (void)
{
  int i;
  afloat a[N+1];
  afloat b[N+1] = {0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60};
  afloat c[N+1] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

  /* Exit on systems without altivec.  */
  signal (SIGILL, sig_ill_handler);
  /* Altivec instruction, 'vor %v0,%v0,%v0'.  */
  asm volatile (".long 0x10000484");
  signal (SIGILL, SIG_DFL);

  main1 (a,b,c);
  main1 (&a[1],b,c);
  main1 (&a[1],b,&c[1]);
}

/* { dg-final { scan-tree-dump-times "vectorized 1 loops" 1 "vect" { xfail *-*-* } } } */
