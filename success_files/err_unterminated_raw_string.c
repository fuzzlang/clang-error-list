
// RUN: %clang_cc1 -fsyntax-only -std=gnu11 -verify=supported %s
// RUN: %clang_cc1 -fsyntax-only -std=c11 -DUNICODE -fraw-string-literals -verify=supported %s

void f() {
  const char* s = R"foo("bar";  // supported-error@* {{missing terminating delimiter}}
}

#ifdef UNICODE
  const char* us = uR"foo("bar"; // unsupported-error {{use of undeclared identifier 'uR'}} cxx-unsupported-error {{expected ';' after expression}}
#endif
