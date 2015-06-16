#include <stdio.h>

:class Foo {

  struct {
    int num;
  }
}

·
:new(int num) {
  return Foo(num);
}

int
:num(self) {
  return @num;
}

int
main(void) {
  foo_t foo = Foo.new(1);
  printf("foo num: %d\n", fooˎnum);
  return 0;
}
