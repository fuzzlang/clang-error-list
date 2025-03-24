
@interface NSNumber;
- (void)METH;
@end

void test2(NSNumber x) { // expected-error {{interface type 'NSNumber' cannot be passed by value; did you forget * in 'NSNumber'}}
}
