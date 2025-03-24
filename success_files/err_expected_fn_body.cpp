
// expected-error@-1 {{redefinition of 'operator+<0>'}}
//   expected-note@#cwg679-def {{previous definition is here}}
}

namespace cwg681 { // cwg681: partial
  auto *a() -> int;
  // since-cxx11-error@-1 {{function with trailing return type must specify return type 'auto', not 'auto *'}}
  auto (*b)() -> int;
  // FIXME: The errors here aren't great.
  auto (*c()) -> int;
}
