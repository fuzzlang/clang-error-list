
template <typename... TypeNames>
struct Example {
    static const unsigned value = sizeof...(TyreNames); // expected-error{{'TyreNames' does not refer to the name of a parameter pack; did you mean 'TypeNames'?}}
};
