
// RUN: %clang_cc1 -fsyntax-only -verify %s

template <typename T>
struct dependent_param_struct {
  void* Foo(T param) __attribute__((alloc_align(2))); // expected-error {{'alloc_align' attribute argument may only refer to a function parameter of integer type}}
};

template <typename T>
void* dependent_param_func(T param) __attribute__((alloc_align(1))); // expected-error {{'alloc_align' attribute argument may only refer to a function parameter of integer type}}

int main() {
    dependent_param_struct<float> d; // expected-note {{in instantiation of template class 'dependent_param_struct<float>' requested here}}
    d.Foo(1.0);

    dependent_param_func<float>(1); // expected-note {{in instantiation of function template specialization 'dependent_param_func<float>' requested here}}

    return 0;
}
