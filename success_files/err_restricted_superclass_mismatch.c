objc
__attribute__((objc_subclassing_restricted))
@interface Leaf @end

__attribute__((objc_subclassing_restricted))
@interface SubClassOfLeaf : Leaf // expected-note {{class is declared here}}
@end

@interface SubClass : SubClassOfLeaf // expected-error {{cannot subclass a class that was declared with the 'objc_subclassing_restricted' attribute}}
@end
