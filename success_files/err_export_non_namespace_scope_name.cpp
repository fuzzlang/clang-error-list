
template <typename T>
struct X {
    struct iterator; // Declaration of iterator inside struct X
};

// Trying to export iterator that is not at namespace scope
export template <typename T>
struct X<T>::iterator; // expected-error {{cannot export 'iterator' as it is not at namespace scope}}
