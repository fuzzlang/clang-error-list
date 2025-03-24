
template<int &&R> struct rval_ref; // expected-warning 0-1{{extension}} expected-error {{non-type template parameter has rvalue reference type 'int &&'}}
