
template<typename T>
void testFunction() {
  T::template operator+<int>::foobar(); // expected-error {{qualified name refers into a specialization of function template 'T::template operator +'}}
}

int main() {
  testFunction<int>();
}
