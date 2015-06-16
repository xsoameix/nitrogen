#include <stdio.h>

:class Foo {}

void
:func(self) {
  puts("foo");
}

:class Bar {

  struct {
    foo_t foo;
    foo_t * ptr;
  }
}

void
:call_foo(self) {
  @foo∘func;
  @ptr·func;
}

int
main(void) {
  foo_t foo = Foo();
  bar_t bar = Bar(foo, &foo);
  bar_t * ptr = &bar;
  bar∘call_foo;
  ptr·call_foo;
  return 0;
}
