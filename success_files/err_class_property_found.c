
#define nil ((void*)0)

@interface A
@property (class) int c;
@end

int test(A *a) {
  return a.c; // expected-error {{property 'c' is a class property; did you mean to access it with class 'A'}}
}
