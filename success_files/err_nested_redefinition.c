
enum e0 { 
    E0 = sizeof(enum e0 { E1 }), // expected-error {{nested redefinition}} 
};
