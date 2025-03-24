
// expected-error@-1 {{declaration does not declare anything}}
struct E { union { int n; }; constexpr E() = default; };
// cxx11-17-error@-1 {{defaulted definition of default constructor cannot be marked constexpr}}
struct F { union { int n = 0; }; constexpr F() = default; };

struct G { union { int n = 0; }; union { int m; }; constexpr G() = default; };
// cxx11-17-error@-1 {{defaulted definition of default constructor cannot be marked constexpr}}
struct H {
    union {
        int n = 0;
    };
    union { // #cwg1460-H-union
        int m;
    };
    constexpr H() {}
};
