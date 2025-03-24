
class A {
public:
    static void g(int);
    void g(int); // expected-error {{static and non-static member functions with the same parameter types cannot be overloaded}}
};
