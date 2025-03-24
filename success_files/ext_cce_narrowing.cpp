
namespace cwg600 {
  class S {
    private:
      double f; // expected-note@#cwg600-f-double {{declared private here}}
    public:
      void func() {
        f = 3.14; // error: cannot access 'f' here
      }
  };
}

namespace std {
  struct type_info {};
  __extension__ typedef __SIZE_TYPE__ size_t;
}

namespace cwg601 { // cwg601: yes
#if __cplusplus >= 201103L
#define MAX __LLONG_MAX__
#else
#define MAX __LONG_MAX__
#endif

#if 0x8000 < -1
#error 0x8000 should be signed
#endif

#if MAX > 0xFFFFFFFF && 0x80000000 < -1
#error 0x80000000 should be signed
#endif

#if __INT_MAX__ == 0x7FFFFFFF
static_assert(0x80000000 < -1, "0x80000000 should be unsigned");
#endif

#if MAX > 0xFFFFFFFFFFFFFFFF && 0x8000000000000000 < -1
#error 0x8000000000000000 should be signed
#endif

#if __cplusplus >= 201103L && __LLONG_MAX__ == 0x7FFFFFFFFFFFFFFF
static_assert(0x8000000000000000 < -1, "0x8000000000000000 should be unsigned");
#endif

#undef MAX
}

namespace cwg602 { // cwg602: yes
  template<class T> struct A {
    template<class U> friend struct A;
  };

  template<class T> struct B {
    class C {
      template<class U> friend struct B;
      typedef int type;
    };
    typename C::type ct; // ok, befriended
  };
  B<int> b;
}

namespace cwg603 { // cwg603: yes
  template<unsigned char> struct S {};
  typedef S<'\001'> S1;
  typedef S<(1ul << __CHAR_BIT__) + 1> S1;
}
