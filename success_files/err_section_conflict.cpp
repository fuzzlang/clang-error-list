
// RUN: %clang_cc1 -verify -fsyntax-only -triple x86_64-linux-gnu %s

template <typename> __attribute__((section("template_fn1"))) void template_fn1() {} // expected-note {{declared here}}
const int const_global_var __attribute__((section("template_fn1"))) = 42;           // expected-error {{'const_global_var' causes a section type conflict with 'template_fn1'}}

int main() {
    return 0;
}
