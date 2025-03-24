
template <typename T>
concept constraint = false;

template <typename T>
struct TemplateFromEnclosing {
    template <typename U>
    friend void bar2() // expected-error {{friend declaration with a constraint that depends on an enclosing template parameter must be a definition}}
    requires constraint<T>;
};
