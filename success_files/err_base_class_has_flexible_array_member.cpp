
struct J {
    int arr[]; // flexible array member
};

struct K : J { }; // expected-error{{base class 'J' has a flexible array member}}
