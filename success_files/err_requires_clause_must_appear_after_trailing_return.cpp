
// expected-error@+4 {{trailing return type must appear before trailing requires clause}}
template <typename T>
auto f3(T a)
  requires true
-> bool;
