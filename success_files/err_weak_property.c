objc
@interface INTF {
    id IVAR; // expected-note {{instance variable is declared here}}
    __weak id II;
    __weak id WID;
    id ID;
    __weak INTF* AWEAK;
    __weak INTF* WI;
}

@property (assign) __weak id pweak;
@property (assign) __weak id WID;
@property (assign) __strong id NOT;
@property (assign) id ID;
@property (assign) INTF* AWEAK;
@property (assign) __weak INTF* WI;

@end

@implementation INTF
@synthesize pweak=IVAR;  // expected-error {{existing instance variable 'IVAR' for __weak property 'pweak' must be __weak}}
@synthesize NOT=II; // expected-error {{existing instance variable 'II' for strong property 'NOT' may not be __weak}}
@synthesize WID;
@synthesize ID;
@synthesize AWEAK; // expected-error {{existing instance variable 'AWEAK' for strong property 'AWEAK' may not be __weak}}
@synthesize WI;
@end
