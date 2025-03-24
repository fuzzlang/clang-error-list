
struct not_trivially_copyable {
    virtual void foo() {}
};

// expected-error@+1{{__builtin_bit_cast source type must be trivially copyable}}
constexpr unsigned long ul = __builtin_bit_cast(unsigned long, not_trivially_copyable{});
