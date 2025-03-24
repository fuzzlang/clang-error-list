
// RUN: %clang_cc1 %s -verify -fopenacc
// expected-error@+1{{OpenACC 'loop' construct can only be applied to a 'for' loop}}
// expected-note@+1{{'loop' construct is here}}
#pragma acc loop
int foo;

struct S {
    // expected-error@+1{{OpenACC 'loop' construct can only be applied to a 'for' loop}}
    // expected-note@+1{{'loop' construct is here}}
    #pragma acc loop
    int i;

    void mem_func() {
        // expected-error@+3{{OpenACC 'loop' construct can only be applied to a 'for' loop}}
        // expected-note@+1{{'loop' construct is here}}
        #pragma acc loop
        int foo;
    }
};
