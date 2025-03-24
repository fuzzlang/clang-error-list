
namespace cwg206 {
  struct S; // Forward declaration of S
}

template<typename T> void f() { 
  cwg206::S s; // expected-error@-1 {{field has incomplete type 'S'}}
} 
