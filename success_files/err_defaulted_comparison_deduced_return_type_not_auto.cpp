
class A {
public:
    friend auto &operator<=>(const A&, const A&) = default; // expected-error@+1 {{deduced return type for defaulted three-way comparison operator must be 'auto', not 'auto &'}}
};
