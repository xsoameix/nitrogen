# Nitrogen

A compiler adding object oriented feature to C

## Features

*   Object oriented
*   Ruby like syntax
*   Compatible with C
*   UTF-8 support
*   Fast, Nitrogen is written in C

## Installation

    $ cmake . && make && sudo make install

## Usage

    $ nitrogen your_source_code.c
    $ cc your_source_code.c.c -o your_application

## Syntax

*   Class Declaration

        :class YourClassName < YourSuperclassName {
        
          struct {
            your instance variables
          }
        }

*   Method Declaration

    A simple function in C

        int
        max(int a, int b) {
          return a > b ? a : b;
        }

    If you add ':' to the function name, then the function will be a class method of the class, just like 'static method' in Java or 'class method' in Ruby.

        int
        :max(int a, int b) {
          return a > b ? a : b;
        }

    If you add 'self' to the function parameters list, then the function will be the instance method of the class, just like Python function declaration.

        int
        :max(self, int a, int b) {
          return a > b ? a : b;
        }

*   Call Class Method

        void
        :class_method(int x, int y) {
          # blah blah
        }

        int
        :instance_method(self, int x, int y) {
          Foo.class_method(x, y);
        }

*   Call Instance Method

    Use middle dot '·' to call instance method

        int
        :foo(self, int x, int y) {
          self·bar(x, y);
        }

    If you're calling the method of 'self', you can emit the self.

        int
        :foo(self, int x, int y) {
          ·bar(x, y);
        }

    Use modifier letter function composition '∘' if you're calling the method of 'struct'.

        int
        :foo(self, int x, int y) {
          foo_t self_struct = * self;
          self_struct∘bar(x, y);
        }

*   Call Superclass Method

    Call parent's method with same name

        int
        :foo(self, int x, int y) {
          super(x, y);
        }

    Equivalent to

        int
        :foo(self, int x, int y) {
          super·bar(x, y);
        }

*   Access Instance Variable

    Use '@' to access the instance variable, just like Ruby

        :class Foo {

          struct {
            int foo;
          }
        }

        int
        :foo(self) {
          return @foo;
        }

*   Create an instance

    Use 'ClassName(...)' to create an instance and the arguments in the parentheses will be assigned to the instance.

        :class Foo {

          struct {
            char * string;
            int number;
          }
        }

        int
        main(void) {
          foo_t foo = Foo("hello", 1);
          return 0;
        }

*   The Class and Instance Type Name

    '··' is the shortcut of the class type name.
    For example, the class type for class FooBar will be translated to 'foo_bar_class_t'

    '·' is the shortcut of the instance type name.
    For example, the instance type for class FooBar will be translated to 'foo_bar_t'

    Example: 

        · *
        :new(int num) {
          · * self = malloc(sizeof(·));
          * self = Foo(num);
          return self;
        }

    Then you can call it:

        foo_t * foo = Foo.new(1);


*   Import the other classes.

    Just add ':require' before class declaration

        #include <stdio.h>

        :require "bar.c"

        class Foo < Bar {

          struct {
            int foo;
          }
        }

        ...

    For more info, please check 'inherit.c' under example folder.

## Examples

Please check the files under 'examples' folder.
