
template <class T>
void Foo(T i) throw(T) { throw i; }

template void Foo(double a) throw();
