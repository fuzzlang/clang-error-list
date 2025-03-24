
typedef __SVInt8_t svint8_t;

void throwing_func() throw(svint8_t); // expected-error {{sizeless type 'svint8_t' (aka '__SVInt8_t') is not allowed in exception specification}}
