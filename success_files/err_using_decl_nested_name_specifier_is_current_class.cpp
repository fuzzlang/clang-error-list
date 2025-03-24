
struct Base {
    int foo();
};

struct Unrelated {
    int foo();
};

struct Subclass : Base {
};

template <class T>
struct C : Base {
    using C::foo; // legal in C++03
};
