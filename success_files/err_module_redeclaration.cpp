
#ifdef FOO
FOO module foo; // expected-note {{previous module declaration is here}}
#endif

#ifdef BAR
BAR module bar; // expected-error {{translation unit contains multiple module declarations}}
BAR module bar; // expected-error {{translation unit contains multiple module declarations}}
#endif
