
consteval int id(int i) { return i; }
constexpr char id(char c) { return c; }

template <typename T>
constexpr int f(T t) { // expected-note {{declared here}}
    return t + id(t);  // expected-note 2{{'f<int>' is an immediate function because its body contains a call to a consteval function 'id' and that call is not a constant expression}}
}

namespace forward_declare_consteval {
template <typename T>
constexpr int f(T t); 

auto a = &f<char>; // ok
auto b = &f<int>;  // expected-error {{immediate function 'f<int>' used before it is defined}} 
                    // expected-note {{in instantiation of function template specialization}}
                    
template <typename T>
constexpr int f(T t) { // expected-note {{'f<int>' defined here}}
    return id(t); // expected-note {{'f<int>' is an immediate function because its body contains a call to a consteval function 'id' and that call is not a constant expression}}
}
}
