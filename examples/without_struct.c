#include <stdio.h>

:class Foo {}

int
main(void) {
  foo_t foo = Foo();
  printf("%s\n", foo.class->name);
  return 0;
}
