
[[using blah: clang::optnone]] extern int n; // expected-error {{attribute with scope specifier cannot follow}} expected-warning {{only applies to functions}}
