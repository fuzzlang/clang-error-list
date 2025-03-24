
#ifndef _MY_HEADER_H
#define _MY_HEADER_H

__thread int t6(void); // expected-error{{type name does not allow storage class to be specified}}

#endif
