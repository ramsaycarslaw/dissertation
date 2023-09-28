#include <stdio.h>
#include "include/libhandler/inc/libhandler.h"

LH_DEFINE_EFFECT1(exception, raise)
LH_DEFINE_VOIDOP1(exception, raise, lh_string)

// handler

lh_value handle_exception_raise(lh_resume *r, lh_value local, lh_value arg) 
{
  printf("Exception raised: %s\n", lh_lh_string_value(arg));
  return lh_value_null;
}

int main() 
{
    printf("Hello, World!\n");
    exception_raise("Test");
    return 0;
}
