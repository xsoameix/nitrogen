#include <stdio.h>

:require "parent.c"

:class Child < Parent {

  struct {
    int y;
  }
}

·
:new(int x, int y) {
  · object = Child();
  object∘initialize(x, y);
  return object;
}

void
:initialize(self, int x, int y) {
  super(x);
  @y = y;
}

int
:y(self) {
  return @y;
}

int
main(void) {
  child_t child = Child.new(1, 2);
  printf("%s(%d, %d)\n", child.class->name, childˎx, childˎy);
  return 0;
}
