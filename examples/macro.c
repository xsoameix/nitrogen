#include <stdio.h>
#include <stdlib.h>
#include <string.h>

:class Ary {

  struct {
    int len;
    int capa;
    void ** objs;
  }
}

void *
:new(void) {
  · * self = malloc(sizeof(·));
  * self = Ary(0, 1, calloc(@capa, sizeof(void *)));
  return self;
}

void *
:add(self, void * obj) {
  size_t size = sizeof(void *);
  if (@len >= @capa) {
    @capa *= 2;
    if (@capa == 0) {
      @capa = 1;
    }
    @objs = realloc(@objs, @capa * size);
  }
  memcpy(@objs + size * @len++, &obj, size);
  return @objs + size * (@len - 1);
}


void *
:get(self, int i) {
  return @objs + sizeof(void *) * i;
}

int
:len(self) {
  return @len;
}

void
:free(self) {
  free(self);
}

:macro each array type { |object index|
  int index = 0;
  for (; index < array·len; index++) {
    type * object = array·get(index);
    yield
  }
}

int
main(void) {
  ary_t * ary = Ary.new();
  ary·add((void *) 1);
  ary·add((void *) 2);
  ary·add((void *) 3);
  ary·add((void *) 4);
  :Ary.each ary int { |obj i|
    printf("\n%d\n ", * obj);
    :Ary.each ary int { |o j|
      printf("%d ", * o);
    }
    printf("\n%d\n ", * obj);
    :Ary.each ary int { |o j|
      printf("%d ", * o);
    }
  }
  :Ary.each ary int { |obj i|
    printf("\n%d", * obj);
  }
  ary·free;
  return 0;
}
