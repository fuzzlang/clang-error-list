
template<typename T, typename U> struct pair;
template<typename ...> struct tuple;

template<typename ... Types>
struct ExpansionLengthMismatch {
    template<typename ... OtherTypes>
    struct Inner {
        typedef tuple<pair<Types, OtherTypes>...> type; // expected-error{{pack expansion contains parameter packs 'Types' and 'OtherTypes' that have different lengths (3 vs. 2)}}
    };
};

ExpansionLengthMismatch<int, long, char>::Inner<unsigned int, unsigned long>::type *il_pairs;
