objective-c
@class UIWindow;

@interface CNAppDelegate

@property (strong, nonatomic) UIWindow *window;

@end

@interface CNAppDelegate ()

@property (nonatomic,retain) id foo;

@end

@implementation CNAppDelegate

@synthesize foo;
@synthesize window = _window;

+ (void)myClassMethod {
    foo = 0; // expected-error {{instance variable 'foo' accessed in class method}}
}

@end
