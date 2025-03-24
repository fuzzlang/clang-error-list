
class BadExceptionSpec {
  void g() throw(
    int(
        ; // expected-error {{unexpected ';' before ')'}}
        ));
};
