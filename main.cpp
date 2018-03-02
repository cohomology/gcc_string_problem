#include <string>

#include <uchar.h>

#include "alloc.h"

extern __attribute__((visibility("default"))) void call(my_string& string);

int main() 
{
  my_string empty;
  call(empty);
}
