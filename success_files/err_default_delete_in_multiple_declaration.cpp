
namespace CWG2876 {
using T = void ();

struct C {
  T e = delete ("hello"); // expected-error {{'= delete' is a function definition and must occur in a standalone declaration}}
};
}
