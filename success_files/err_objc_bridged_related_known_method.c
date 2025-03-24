
typedef struct __attribute__((objc_bridge_related(NSColor,colorWithCGColor:,CGColor))) CGColor *CGColorRef;

@interface NSColor
+ (NSColor *)colorWithCGColor:(CGColorRef)cgColor;
- (CGColorRef)CGColor;
@end

NSColor *Test1(NSColor *nsColor, CGColorRef newColor) {
    nsColor = newColor; // expected-error {{'CGColorRef' (aka 'CGColor *') must be explicitly converted to 'NSColor *'; use '+colorWithCGColor:' method for this conversion}}
    return nsColor;
}
