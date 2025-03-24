
namespace Conversion {
  struct Ptr {
    operator int*();
  };

  struct NotPtr {
    explicit operator int*(); // expected-note {{conversion}}
  };

  void testDelete() {
    Ptr p;
    NotPtr np;

    delete p;
    delete np; // expected-error {{converting delete expression from type 'NotPtr' to type 'int *' invokes an explicit conversion function}}
  }
}
