
module; // global module fragment
export module Foo; // module declaration
module :private; // first private module fragment
module :private; // expected-error {{private module fragment redefined}}
