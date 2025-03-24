
struct T {
    T() = default;
    T(const T&) = delete;
};

T a = delete("hello"); // expected-error {{only functions can have deleted definitions}}
