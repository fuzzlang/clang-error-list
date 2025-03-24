
struct BadDerived;
struct BadBase { 
    operator BadDerived&(); 
};
struct BadDerived : BadBase {};

void testConditional(int i1) {
    BadBase bb;
    BadDerived bd;
    (void)(i1 ? bb : bd); // expected-error {{conditional expression is ambiguous; 'BadBase' can be converted to 'BadDerived' and vice versa}}
}
