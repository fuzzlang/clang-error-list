
struct A {
    ~A() {}
};

void f(A a) { 
    a.~decltype(auto)(); // expected-error {{'decltype(auto)' not allowed here}}
}
