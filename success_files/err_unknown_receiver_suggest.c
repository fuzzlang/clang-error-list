
@interface NSString // expected-note{{'NSString' declared here}}
+ (int)method:(int)x;
@end

void test_message_send(void) {
    [NSstring method:17]; // expected-error{{unknown receiver 'NSstring'; did you mean 'NSString'?}}
}
