
@interface MyObject
@property (nonatomic, atomic, readonly) float propertyName; // expected-error {{property attributes 'atomic' and 'nonatomic' are mutually exclusive}}
@end

@implementation MyObject
// Implementation details
@end
