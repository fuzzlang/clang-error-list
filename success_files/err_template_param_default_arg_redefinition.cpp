
template<class T1, 
         class T2 = int> // expected-note{{previous default template argument defined here}}
  class B3;

template<class T1, typename T2> class B3;

template<class T1, 
         typename T2 = float> // expected-error{{template parameter redefines default argument}}
  class B3;
