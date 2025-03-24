
namespace foo {
    void function() {}
}

namespace [[]] bad = foo; // expected-error {{attributes cannot be specified on namespace alias}}
