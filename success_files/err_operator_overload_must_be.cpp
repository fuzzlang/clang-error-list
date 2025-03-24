
struct A {
    friend A operator|(const A& r); // expected-error {{overloaded 'operator|' must be a binary operator (has 1 parameter)}}
};
