
class A {
public:
    friend A &operator=(A&, char&);
};

A &operator=(A& a, char& b) { // expected-error@-1 {{overloaded 'operator+=' cannot be a static member function}}
    // implementation
    return a;
}
