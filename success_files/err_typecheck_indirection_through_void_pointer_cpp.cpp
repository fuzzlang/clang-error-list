
void *V() {
    return nullptr; // necessary initialization
}

__typeof(*V()) f5(); // expected-error {{indirection not permitted on operand of type 'V' (aka 'void *')}}
