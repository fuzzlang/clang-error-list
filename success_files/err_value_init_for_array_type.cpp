
namespace test8 {
typedef int arr[];
int v = arr(); // expected-error {{array types cannot be value-initialized}} \
               // expected-error {{cannot initialize a variable of type 'int' with an rvalue of type 'arr'}}
}
