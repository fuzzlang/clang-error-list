
int *not_class_member() [[clang::lifetimebound]]; // expected-error {{non-member function has no implicit object parameter}}
