
@interface I
@end

void testFunction() {
    __strong I *__strong test1; // expected-error {{the type 'I *__strong' is already explicitly ownership-qualified}}
}
