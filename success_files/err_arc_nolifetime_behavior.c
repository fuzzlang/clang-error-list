
__attribute__((objc_arc_weak_reference_unavailable))
@interface NSOptOut1072  // expected-note {{class is declared here}}
@end

@interface sub : NSOptOut1072 @end // expected-note 2 {{class is declared here}}

int main() {
    __weak sub *ns1; // expected-error {{class is incompatible with __weak references}}
    __weak NSOptOut1072 *w2; // expected-error {{class is incompatible with __weak references}}
    
    id obj;
    ns1 = (__weak sub *)obj; // expected-error {{assignment of a weak-unavailable object to a __weak object}} 
}
