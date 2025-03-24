
using FourInts = int __attribute__((__vector_size__(16)));

enum E {};
E e;
FourInts four_ints;

void test() {
    (void)(four_ints ? e : e); // expected-error {{enumeration type 'E' is not allowed in a vector conditional}}
}
