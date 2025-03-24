
namespace MissingBrace {
  struct S { // expected-error {{missing '}' at end of definition of 'MissingBrace::S'}}
    int f();
  // };
  namespace N { int g(); } // expected-note {{still within definition of 'MissingBrace::S' here}}
}
