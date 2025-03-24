
struct S {
    char c : (unsigned __int128)0xffffffffffffffff + 2; // expected-error {{bit-field 'c' is too wide (18446744073709551617 bits)}}
};
