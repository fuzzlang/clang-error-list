
const unsigned char a[] = {
#embed <jk.txt> limit(12345678901234567890) prefix() limit(12345678901234567890) // expected-error@-2 {{integer literal is too large to be represented in any integer type}}
};
