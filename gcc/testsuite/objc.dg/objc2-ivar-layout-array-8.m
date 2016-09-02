/* APPLE LOCAL file radar 5082000 */
/* Test of ivar layour involving array ivars. */
/* { dg-do run { target *-*-darwin* } } */
/* { dg-options "-mmacosx-version-min=10.5 -framework Foundation -fobjc-gc" } */

#include <objc/runtime.h>
#include <Foundation/Foundation.h>

typedef struct _NSAttributeDictionaryElement {
    NSUInteger hash;
    id key;
    id value;
} NSAttributeDictionaryElement;

@interface NSTableOptions : NSObject {
    NSUInteger numElements;
    __weak id refCount;
    NSAttributeDictionaryElement elements[1][2][3];
    __weak id tail_end;
}
@end

@implementation NSTableOptions
@end

const char expected_strong [] = {0x01, 0x30, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0x02, 0x10, 0};

const char expected_weak [] = {0x21, 0xf0, 0x30, 0x01, 0};

int main()
{
        int i = 0;
        const char *ivar_layout_string = (const char*)class_getIvarLayout([NSTableOptions class]);
        if (strcmp (ivar_layout_string, expected_strong))
          abort ();

	ivar_layout_string = (const char*)class_getWeakIvarLayout([NSTableOptions class]);
	if (strcmp (ivar_layout_string, expected_weak))
	  abort ();

        return 0;
}

