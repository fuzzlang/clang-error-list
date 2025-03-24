
template<typename T>
class B {
public:
    B(T) {}
};

template<> B(int) -> B<int>; // expected-error {{deduction guide cannot be explicitly specialized}}
