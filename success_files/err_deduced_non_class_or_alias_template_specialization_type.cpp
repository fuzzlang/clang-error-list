
template <typename T>
using AFoo = T;

int main() {
    AFoo s = {1}; // expected-error {{alias template 'AFoo' requires template arguments; argument deduction only allowed for}}
    return 0;
}
