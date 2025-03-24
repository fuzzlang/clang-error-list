
namespace A2 {
  struct CC {
    struct NC {
      void m();
    };
  };
}

void A2::CC::NC::m(); // expected-error{{out-of-line declaration of a member must be a definition}}
