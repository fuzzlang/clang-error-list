
template<typename T>
struct X0 {
  template<typename U>
  struct InnerTemplate : public T { };  // expected-error {{base specifier must name a class}}
};

int main() {
    X0<int>::InnerTemplate<double> obj;
}
