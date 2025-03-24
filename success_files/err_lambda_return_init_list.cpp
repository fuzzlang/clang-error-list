
void infer_void_return_type(int i) {
    return [](int x) {
        switch (x) {
        case 2: return { 1, 2.0 }; // expected-error{{cannot deduce}}
        }
    }(7);
}
