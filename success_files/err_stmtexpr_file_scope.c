
struct S {
    int arr[]; // expected-error {{fields must have a constant size: 'variable length array in structure' extension will never be supported}}
};

int a() {
    return 0;
}

int GH48579_3 = ({a();}); // both-error {{statement expression not allowed at file scope}}
