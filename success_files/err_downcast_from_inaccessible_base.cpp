
namespace cwg54 {
class A {
  private:
    int a;
};

class B : private A {
  public:
    B() {}
};

void test() {
    A a;
    B &sba = static_cast<B&>(a); // expected-error@-1 {{cannot cast 'cwg54::B' to its private base class 'cwg54::A'}}
                                     // expected-note@#cwg54-B {{declared private here}}
}
