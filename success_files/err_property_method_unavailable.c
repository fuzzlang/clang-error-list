
@interface Foo {
    int _x;
}
@property(nonatomic,readonly) int x;
- (void)setX:(int)x __attribute__ ((deprecated)); // expected-note 2 {{'setX:' has been explicitly marked deprecated here}}
- (int)x __attribute__ ((unavailable)); // expected-note {{'x' has been explicitly marked unavailable here}}
@end

@implementation Foo
- (void)setX:(int)x {
    _x = x;
}
- (int)x {
    return _x;
}
@end

void testUserAccessorAttributes(Foo *foo) {
    foo.x = foo.x; // expected-error {{property access is using 'x' method which is unavailable}}
}
