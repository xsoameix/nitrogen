#include <stdio.h>

:class Foo {}

void
:func(self) {
  puts("foo");
}

:class Bar {

  struct {
    foo_t * foo_p;
    foo_t foo;
  }
}

void
:call_foo(self) {
  @foo_p·func;
  @fooˎfunc;
}

int
main(void) {
  foo_t foo = {&Foo};
  bar_t bar = {&Bar, &foo, foo};
  barˎcall_foo;
  bar_t * bar_p = &bar;
  bar_p·call_foo;
  return 0;
}
