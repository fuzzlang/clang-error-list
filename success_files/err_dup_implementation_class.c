
@implementation rdar14024851 // expected-error {{reimplementation}}

// Duplicate interface implementation
@interface MyClass : NSObject
- (void)someMethod;
@end

@implementation MyClass
- (void)someMethod {
    // Method implementation
}
@end

@implementation MyClass // expected-error {{reimplementation}}
@end
