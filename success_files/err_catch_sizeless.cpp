
namespace std {
struct type_info;
}

typedef __SVInt8_t svint8_t;

void test_exception_handling() {
  try {
    // code that might throw an exception
  } catch (svint8_t) { // expected-error {{cannot catch sizeless type 'svint8_t'}}
    // exception handling code
  }
}
