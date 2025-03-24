
// RUN: %clang_cc1 -std=c++2a -verify %s

void *operator new(__SIZE_TYPE__, void*);

namespace postfix_after_unary {
    struct A { int n; };
    int &a = new A->n; // expected-error {{expression cannot be followed by a postfix '->' operator; add parentheses}}
}
