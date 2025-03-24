
void illegal_argument_1(__externref_t table[]);  // expected-error {{cannot use WebAssembly table as a function parameter}}

void foo() {
    __externref_t myTable[10];
    illegal_argument_1(myTable);
}
