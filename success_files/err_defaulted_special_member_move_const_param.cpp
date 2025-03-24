
class Const {
public:
    Const(const Const&&) = default; // expected-error {{the parameter for an explicitly-defaulted move constructor may not be const}}
};
