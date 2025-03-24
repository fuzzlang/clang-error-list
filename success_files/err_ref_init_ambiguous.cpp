
struct Base {};

struct DerivedA : Base {};
struct DerivedB : Base {};

struct ConvertibleToBothDerivedRef {
    operator DerivedA&(); // Conversion to DerivedA reference
    operator DerivedB&(); // Conversion to DerivedB reference
};

ConvertibleToBothDerivedRef both;

void func() {
    Base &br1 = both; // expected-error{{reference initialization of type 'Base &' with initializer of type 'ConvertibleToBothDerivedRef' is ambiguous}}
}
