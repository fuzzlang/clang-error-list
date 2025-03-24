
typedef struct __attribute__((objc_bridge_related(PNsColor, colorWithCGColor:, CGColor))) CGColor2 *CGColorRef2; // expected-note 2 {{declared here}}

@interface NSColor
+ (NSColor *)colorWithCGColor:(CGColorRef2)cgColor;
- (CGColorRef2)CGColor;
@end

@interface NSTextField
- (void)setBackgroundColor:(NSColor *)color;
- (NSColor *)backgroundColor;
@end

typedef int PNsColor; // expected-note 2 {{declared here}}

NSColor *Test3(NSTextField *textField, CGColorRef2 newColor) {
    textField.backgroundColor = newColor; // expected-error {{'PNsColor' must be name of an Objective-C class to be able to convert 'CGColorRef2' (aka 'struct CGColor2 *') to 'NSColor *'}}
}
