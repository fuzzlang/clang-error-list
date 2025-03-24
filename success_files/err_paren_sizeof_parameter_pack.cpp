
template<typename... Type>
struct Example {
    static const unsigned value = sizeof... Type; // expected-error{{missing parentheses around the size of parameter pack 'Type'}}
};
