
module B; // implicitly imports B.

int foo() { return 10; }

import C; // expected-error {{imports must immediately follow the module declaration}}
