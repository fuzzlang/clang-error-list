
struct A {
    friend bool operator==(const A&, const A&) = default;
    friend bool operator!=(const A&, const A&) = default;
    friend std::strong_ordering operator<=>(const A&, const A&) = default;
};

struct C {
    friend bool operator==(const C&, const C&); // expected-note {{previous}} 
    friend bool operator!=(const C&, const C&) = default; // expected-note {{previous}} 
    friend std::strong_ordering operator<=>(const C&, const C&); // expected-note {{previous}} 
};

struct E {
    A a;
    C c; // cxx2a-note 2{{non-constexpr comparison function would be used to compare member 'c'}}
    A b;
    friend constexpr bool operator==(const E&, const E&) = default; // cxx2a-error {{cannot be declared constexpr}} 
    friend constexpr bool operator!=(const E&, const E&) = default;
    friend constexpr std::strong_ordering operator<=>(const E&, const E&) = default; // cxx2a-error {{cannot be declared constexpr}} 
};
