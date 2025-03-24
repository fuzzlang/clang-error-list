
namespace cwg574 {
    struct C {
        C &operator=(const C&) &; // #cwg574-C-copy-assign
    };

    struct Test {
        friend C &C::operator=(const C&); // expected-error@-1 {{friend declaration of 'operator=' does not match any declaration in 'cwg574::C'}}
    };
}
