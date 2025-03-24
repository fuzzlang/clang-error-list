
class A {
private:
    ~A() {}
};

int main() {
    A* x = new A();
    delete x; // expected-error {{calling a private destructor}}
    return 0;
}
