
void test(void) {
  struct S { int x, y; } s = {}; // compat-warning {{use of an empty initializer is incompatible with C standards before C23}} \
                                    pedantic-warning {{use of an empty initializer is a C23 extension}}
  int i = {}; // compat-warning {{use of an empty initializer is incompatible with C standards before C23}} \
                                  pedantic-warning {{use of an empty initializer is a C23 extension}}
  int j = (int){}; // compat-warning {{use of an empty initializer is incompatible with C standards before C23}} \
                      pedantic-warning {{use of an empty initializer is a C23 extension}}

  int unknown_size[] = {}; // pedantic-warning {{zero size arrays are an extension}} \
                              pedantic-warning {{use of an empty initializer is a C23 extension}} \
                              compat-warning {{use of an empty initializer is incompatible with C standards before C23}}
  int vla[i] = {}; // compat-warning {{use of an empty initializer is incompatible with C standards before C23}} \
                      pedantic-warning {{use of an empty initializer is a C23 extension}}
  int *compound_literal_vla = (int[i]){}; // compat-warning {{use of an empty initializer is incompatible with C standards before C23}} \
}
