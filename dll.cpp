#include <string>
#include <uchar.h>

#include "alloc.h"

__attribute__((visibility("default"))) void call(my_string& string);

void call(my_string& string) 
{
   string.append(u"Hello World");
}


