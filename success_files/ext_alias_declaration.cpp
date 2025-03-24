
template <typename T> using id = T;

struct null1_t {};

struct S {
  void func() {}
};

void example() {
  id<null1_t (S::*)()> var; // expected-error@-1 {{no viable conversion from 'struct null1_t' to 'int (cwg395::S::*)()'}}
  // expected-note@#cwg395-conv-func {{candidate template ignored: couldn't infer template argument 'T'}}
}
