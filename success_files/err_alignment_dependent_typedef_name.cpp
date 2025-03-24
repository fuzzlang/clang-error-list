
template <typename T>
void Fun(T A) {
  typedef int __attribute__((__aligned__(A))) T1; // expected-error {{requested alignment is dependent but declaration is not dependent}}
  int k1[__alignof__(T1)];
}
