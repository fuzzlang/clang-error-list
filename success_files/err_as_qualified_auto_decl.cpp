
void f([[clang::address_space(1)]] int* param) { // expected-warning {{applying attribute 'address_space' to a declaration is deprecated; apply it to the type instead}}
  int* local2 [[clang::address_space(1)]]; // expected-error {{automatic variable qualified with an address space}} expected-warning {{applying attribute 'address_space' to a declaration is deprecated; apply it to the type instead}}
}

int main() {
    return 0;
}
