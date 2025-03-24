
using FourInts = int __attribute__((__vector_size__(16)));

FourInts four_ints;

void Operands() {
    // This line should trigger the expected error
    (void)(four_ints ? four_ints : throw 1); // expected-error {{GNU vector conditional operand cannot be a throw expression}}
}
