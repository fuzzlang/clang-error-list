
struct cwg125_A { 
    struct cwg125_B {}; 
};

cwg125_A::cwg125_B cwg125_C();

namespace cwg125 {
    struct X {
        friend cwg125_A::cwg125_B::cwg125_C(); // #cwg125_C
        // expected-error@#cwg125_C {{missing return type for function 'cwg125_C'; did you mean the constructor name 'cwg125_B'?}}
    };
}
