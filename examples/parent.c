:class Parent {

  struct {
    int x;
  }
}

void
:initialize(self, int x) {
  @x = x;
}

int
:x(self) {
  return @x;
}
