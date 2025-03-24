
namespace cwg1947 { // cwg1947: 3.5
#if __cplusplus >= 201402L
unsigned o = 0'01;  // ok
unsigned b = 0b'01;  
// expected-error@-1 {{invalid digit 'b' in octal constant}}
unsigned x = 0x'01;
#endif
}
