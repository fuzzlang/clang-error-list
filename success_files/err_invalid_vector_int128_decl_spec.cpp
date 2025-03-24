
void test() {
    __vector bool __int128 v1_bi128; // expected-error {{use of '__int128' with '__vector' requires extended Altivec support (available on POWER8 or later)}}
}
