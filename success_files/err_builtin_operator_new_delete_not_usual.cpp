
typedef __SIZE_TYPE__ size_t;

void *NP = nullptr;

void operator delete(void *, size_t); // expected-note {{candidate}}

void test_sized_delete() {
    __builtin_operator_delete(NP, 4); // expected-error {{call to '__builtin_operator_delete' selects non-usual deallocation function}}
}
