
union MyUnion {
    int &i; // expected-error {{union member 'i' has reference type 'int &'}}
};
