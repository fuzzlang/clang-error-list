
namespace g { enum { o = 0 }; }

void foo() {
    namespace a { typedef g::o o; } // expected-error{{namespaces can only be defined in global or namespace scope}}
}
