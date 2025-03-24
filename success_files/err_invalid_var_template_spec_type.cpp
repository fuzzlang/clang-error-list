
namespace explicit_instantiation {
  template<typename T>
  T pi0a = T(3.1415926535897932385);  // expected-note {{variable template 'pi0a' declared here}}
  
  template float pi0a<int>; // expected-error {{type 'float' of explicit instantiation of 'pi0a' does not match expected type 'int'}}
}
