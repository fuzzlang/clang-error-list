
namespace pr15133 {
  namespace ns {
    const int V1 = 1;   // expected-note {{declared here}}
  }
  
  struct C1 {
    enum E1 { V2 = 2 }; // expected-note {{declared here}}
    static const int V3 = 3; // expected-note {{declared here}}
  };

  void func_1(int x) {
    switch(x) {
      case ns::V1:: break; // expected-error{{'V1' cannot appear before '::' because it is not a class, namespace, or enumeration; did you mean ':'?}}
    }
  }
}
