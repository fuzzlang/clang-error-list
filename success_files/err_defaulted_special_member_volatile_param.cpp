
class Volatile {
public:
    Volatile(volatile Volatile&&) = default; // expected-error {{the parameter for an explicitly-defaulted move constructor may not be volatile}}
};
