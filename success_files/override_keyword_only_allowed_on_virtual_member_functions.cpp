
class B2 {
public:
    bool operator==(const B2&) const override; // expected-error {{only virtual member functions}}
};
