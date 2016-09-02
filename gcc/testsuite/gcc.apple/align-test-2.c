/* APPLE LOCAL file Macintosh alignment */

/* { dg-do run } */
/* { dg-options "-Wno-long-long" } */

/*
 * Macintosh compiler alignment test for alignment extensions in GCC 3.
 * Fred Forsman
 * Apple Computer, Inc.
 * (C) 2000-2002.
 * Last modified 2002-1-22.
 */
 
 /* Check whether we are testing GCC 3 or later.  */
#ifdef __GNUC__
#if __GNUC__ >= 3
    #define GCC3 1
#endif
#endif

#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define Q(x) #x, x

typedef unsigned char UINT8;
typedef unsigned long UINT32;

static int bad_option = 0;
static int flag_verbose = 0;
static int nbr_failures = 0;

/* === alignment modes === */

typedef struct S1 {
    UINT8	f1;
} S1;

#pragma options align=mac68k

typedef struct S2 {
    UINT8	f1;
} S2;

#pragma options align=native

typedef struct S3 {
    UINT8	f1;
} S3;

#pragma options align=reset
/* Should be mac68k mode here.  */

#pragma options align=reset
/* Should be power mode here.  */

typedef struct S4 {
    UINT8	f1;
    double	f2;
} S4;

#pragma options align=natural

typedef struct S5 {
    UINT8	f1;
    double	f2;
} S5;

typedef struct S6 {
    UINT8	f1;
    double	f2;
    UINT8	f3;
} S6;

#pragma options align=reset
/* Should be power mode here.  */

#pragma options align=packed

typedef struct S7 {
    UINT8	f1;
    UINT32	f2;
} S7;

#pragma options align=reset
/* Should be power mode here.  */

typedef struct S8 {
    UINT8	f1;
    UINT32	f2;
} S8;

static void check(char * rec_name, int actual, int expected, char * comment)
{
    if (flag_verbose || (actual != expected)) {
        printf("%-20s = %2d (%2d) ", rec_name, actual, expected);
        if (actual != expected) {
            printf("*** FAIL");
            nbr_failures++;
        } else
            printf("    PASS");
        printf(": %s\n", comment);
    }
}

static void check_option(char *option)
{
    if (*option == '-') {
        if (strcmp(option, "-v") == 0)
            flag_verbose = 1;
        else {
            fprintf(stderr, "*** unrecognized option '%s'.\n", option);
            bad_option = 1;
        }
    } else {
        fprintf(stderr, "*** unrecognized option '%s'.\n", option);
        bad_option = 1;
    }
}

int main(int argc, char *argv[])
{
    int i;
    
    for (i = 1; i < argc; i++)
        check_option(argv[i]);
    
    if (bad_option)
        return 1;

#ifndef GCC3
    printf("This test requires GCC 3");
    return 1;
#endif

    check(Q(sizeof(S1)), 1, "struct with 1 char; power mode");
    check(Q(sizeof(S2)), 2, "struct with 1 char; mac68k mode");
    check(Q(sizeof(S3)), 1, "struct with 1 char; native mode");
    check(Q(sizeof(S4)), 12, "struct with char, double; power mode");
    check(Q(offsetof(S4, f2)), 4, "offset of double in a struct with char, double; power mode");
    check(Q(sizeof(S5)), 16, "struct with char, double; natural mode");
    check(Q(offsetof(S5, f2)), 8, "offset of double in a struct with char, double; natural mode");
    check(Q(sizeof(S6)), 24, "struct with char, double, char; natural mode");
    check(Q(sizeof(S7)), 5, "struct with char, long; packed mode");
    check(Q(sizeof(S8)), 8, "struct with char, long; power mode");

    if (nbr_failures > 0)
    	return 1;
    else
    	return 0;
}
