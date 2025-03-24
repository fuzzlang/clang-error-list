objective-c
@class NSObject;

@interface I {
    __attribute__((iboutletcollection(int))) id ivar5; // expected-error {{type argument of iboutletcollection attribute cannot be a builtin type}}
}
@end
