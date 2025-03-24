
class MyClass {
public:
  static void* operator new(signed char) throw(); // expected-error {{'operator new' takes type size_t}}
};
