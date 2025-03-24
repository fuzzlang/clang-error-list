
namespace PR10925 {
  template< int mydim, typename Traits >
  class BasicGeometry
  {
    typedef int some_type_t;
  };

  template<class ctype, int mydim, int coorddim>
  class MockGeometry : BasicGeometry<mydim, int>{
    using typename BasicGeometry<mydim, int>::operator[]; // expected-error {{typename is allowed for identifiers only}}
  };
}
