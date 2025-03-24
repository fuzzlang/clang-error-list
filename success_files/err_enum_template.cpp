
namespace PR12106 {
  template<typename E> struct Enum {
    Enum() : m_e(E::Last) {}
    E m_e;
  };

  enum eCOLORS { Last }; // expected-error {{enumeration cannot be a template}}
  template<typename E> enum Enum<E>::eCOLORS { e };
}
