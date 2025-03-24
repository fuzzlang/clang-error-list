
void goto_redef(int n) {
  a:  if constexpr(sizeof(n) == 4) // expected-error {{redefinition}} expected-note {{constexpr if}}
      a: goto a; // expected-error {{redefinition}} expected-error {{cannot jump}}
    else
      a: goto a; // expected-error {{redefinition}} expected-error {{cannot jump}}
}
