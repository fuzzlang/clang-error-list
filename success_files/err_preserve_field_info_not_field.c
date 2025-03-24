
struct MyStruct {
    int x;
};

int main() {
    MyStruct myStruct;
    int arg = myStruct.x; // this is a field access

    return __builtin_preserve_field_info(arg, 1); // expected-error {{__builtin_preserve_field_info argument 1 not a field access}}
}
