
typedef struct __attribute__((objc_bridge_related(NSColor, colorWithCGColor, CGColor))) CGColor *CGColorRef2NotOk; // expected-error {{expected a class method selector with single argument, e.g., 'colorWithCGColor:'}}
