
namespace PR5918 { // Look for template operator new overloads.
  struct S { template<typename T> static void* operator new(size_t, T); };
  void test() {
    (void)new(0) S;
    delete 0; // expected-error {{calling a private destructor}}
  }
}

namespace Test1 {

void f() {
  (void)new int[10](1, 2); // expected-error {{array 'new' cannot have initialization arguments}}
}
