
typedef struct __attribute__((objc_bridge_related(XNSColor,colorWithCGColor:,CGColor))) CGColor1 *CGColorRef1; // expected-note {{declared here}}

@interface NSColor
+ (NSColor *)colorWithCGColor:(CGColorRef)cgColor;
- (CGColorRef)CGColor;
@end

@interface NSTextField 
- (void)setBackgroundColor:(NSColor *)color;
- (NSColor *)backgroundColor;
@end

NSColor * Test2(NSTextField *textField, CGColorRef1 newColor) {
    textField.backgroundColor = newColor; // expected-error {{could not find Objective-C class 'XNSColor' to convert 'CGColorRef1' (aka 'struct CGColor1 *') to 'NSColor *'}}
}
