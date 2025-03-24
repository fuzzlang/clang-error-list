
namespace std {
  class type_info;
}

template<typename T>
struct TypeId1 {
  const std::type_info &f() {
    return typeid(T); // expected-error-re 2{{type operand 'void () {{const|&}}' of 'typeid' cannot have '{{const|&}}' qualifier}}
  }
};

template struct TypeId1<void() const>; // expected-note{{instantiation of}}
