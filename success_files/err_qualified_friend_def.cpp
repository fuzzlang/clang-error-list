
void f1();

struct Y {
    friend void ::f1() { } // expected-error{{friend function definition cannot be qualified with '::'}}
};
