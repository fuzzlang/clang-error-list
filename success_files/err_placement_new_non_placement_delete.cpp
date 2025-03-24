
__extension__ typedef __SIZE_TYPE__ size_t;

namespace cwg429 {
  struct A {
    static void *operator new(size_t, size_t);
    static void operator delete(void*, size_t); // #cwg429-delete
  } *a = new (0) A; // expected-error {{'new' expression with placement arguments refers to non-placement 'operator delete'}}
                    // expected-note@#cwg429-delete {{here}}
}
