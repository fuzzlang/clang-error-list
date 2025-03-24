objc
@interface BRC : NSObject
- (void)removeReach:(NSObject*)observer;
@end

@implementation BRC : NSObject
- (void)removeReach:(NSObject*)observer // expected-note {{previous declaration is here}}
{
}

- (void)removeReach:(NSObject*)observer // expected-error {{duplicate declaration of method 'removeReach:'}}
{
}
@end
