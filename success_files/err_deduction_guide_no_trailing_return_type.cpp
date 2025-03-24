
template<typename A3>
class B3 {
    template<bool = true>
    B3();
}; B3(); // expected-error {{deduction guide declaration without trailing return type}}
