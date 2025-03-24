
struct MyStruct {
    int a;
    double b;
};

int main() {
    __builtin_dump_struct(1, 2); // expected-error {{expected pointer to struct as 1st argument to '__builtin_dump_struct', found 'int'}}
    return 0;
}
