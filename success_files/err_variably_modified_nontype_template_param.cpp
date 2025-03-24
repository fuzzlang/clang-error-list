
struct HasNonConstantValue {
    static unsigned int value;
};

template<typename T>
struct X1 {
    template<int (&Array)[T::value]> // expected-error{{non-type template parameter of variably modified type 'int (&)[HasNonConstantValue::value]'}}
    struct Inner {
    };
};

X1<HasNonConstantValue> x1b; // expected-note{{in instantiation of}}
