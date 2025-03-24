
template<_Atomic int ci> struct AtomicInt; // expected-error {{cannot have type '_Atomic(int)'}}

// we allow vector types as an extension
typedef __attribute__((ext_vector_type(4))) int VI4;
typedef __attribute__((ext_vector_type(4))) float VF4;
template<VI4> struct VectorInt; // cxx17-error {{cannot have type 'VI4'}}
template<VF4> struct VectorFloat; // cxx17-error {{cannot have type 'VF4'}}

struct A2 {};

struct RRef {
  int &&r; // cxx20-note 1+{{'RRef' is not a structural type because it has a non-static data member of rvalue reference type}}
};

// class types with all public members and bases, no mutable state, and no rvalue references.
struct B : A, public A2 {
  int a;
private:
  void f();
  static int s;
public:
  float g;
  int &r = a;
  void *p;
  A2 a2;
  RRef *ptr_to_bad;
  RRef &ref_to_bad = *ptr_to_bad;
  _Complex int ci;
  _Complex float cf;
  _BitInt(42) ei;
  VI4 vi4;
  VF4 vf4;
};

template<B> struct ClassNTTP {}; // cxx17-error {{cannot have type 'B'}}

template<RRef> struct WithRRef {}; // cxx17-error {{cannot have type 'RRef'}}
