
struct Bad {
    bool &operator<(const Bad&) const = default; // expected-error {{return type for defaulted relational comparison operator must be 'bool', not 'bool &'}}
};
