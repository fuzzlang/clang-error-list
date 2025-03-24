
struct Y {
  int x;
};

template<typename T>
struct X1 {
  int f(T* ptr, int T::*pm) { // expected-error{{member pointer}}
    return ptr->*pm;
  }
};

template struct X1<Y>;
template struct X1<int>; // expected-note{{instantiation}}
