
static const int wrong_init __attribute__(( type_tag_for_datatype(zzz, int) )) = f(100); // expected-error {{'type_tag_for_datatype' attribute requires the initializer to be an integral constant expression}}

int f(int a) {
    return a;
}
