
__attribute__((objc_arc_weak_reference_unavailable))
@interface NOWEAK
+ (id)new;
@end

NOWEAK *Test1() {
    NOWEAK *strong1 = [NOWEAK new];
    __weak id weak1;
    weak1 = strong1; // expected-error {{assignment of a weak-unavailable object to a __weak object}}
    
    __weak id weak2 = strong1; // expected-error {{assignment of a weak-unavailable object to a __weak object}}
    return (__weak id)strong1; // expected-error {{cast of weak-unavailable object of type 'NOWEAK *' to a __weak object of type '__weak id'}}
}
