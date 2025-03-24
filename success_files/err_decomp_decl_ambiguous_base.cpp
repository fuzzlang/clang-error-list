
struct A { int a; };
namespace MultipleClasses {
    struct B : A { int a; };
    struct C { int a; };
    struct D : A, C {};
    struct E : virtual A {};
    struct F : A, E {}; // expected-warning {{direct base 'A' is inaccessible due to ambiguity}}

    void test() {
        auto [f] = F(); // expected-error-re {{cannot decompose members of ambiguous base class 'A' of 'F':{{.*}}struct MultipleClasses::F -> A{{.*}}struct MultipleClasses::F -> E -> A}}
    }
}
