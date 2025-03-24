
namespace std {
  template <class X>
  class initializer_list {
    public: const X *a, *b;
    initializer_list();
  };
}

class Foo {
public:
  Foo();
  Foo(std::initializer_list<int>);
  bool operator==(const Foo);
  Foo operator+(const Foo);
};

#define EQ(x,y) (void)(x == y)  // expected-note 6{{defined here}}
void test_EQ() {
  Foo F;
  F = Foo{1,2};

  EQ(F,F);
  EQ(F,Foo());
  EQ(F,Foo({1,2,3}));
  EQ(Foo({1,2,3}),F);
  EQ((Foo{1,2,3}),(Foo{1,2,3}));
  EQ(F, F + F);
  EQ(F, Foo({1,2,3}) + Foo({1,2,3}));
  EQ(F, (Foo{1,2,3} + Foo{1,2,3}));

  EQ(F,Foo{1,2,3});
  EQ(F, Foo({1,2,3,4})); // This line will trigger the error: too many arguments in macro invocation
}
