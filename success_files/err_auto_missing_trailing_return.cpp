
#if __cplusplus >= 201103L
namespace cwg681 { // cwg681: partial
  auto *a() -> int; // expected-error@-1 {{function with trailing return type must specify return type 'auto', not 'auto *'}}
  auto (*b)() -> int; // expected-error@-1 {{function with trailing return type must specify return type 'auto', not 'auto *'}}
  auto (*c()) -> int; // expected-error@-1 {{expected function body after function declarator}}
  auto ((*d)()) -> int; // expected-error@-1 {{declaration of variable 'd' with deduced type 'auto ((*)())' requires an initializer}}
                        // expected-error@-2 {{expected ';' after top level declarator}}

  auto (*e())() -> int; // expected-error@-1 {{function with trailing return type must specify return type 'auto', not 'auto *'}}
}
#endif
