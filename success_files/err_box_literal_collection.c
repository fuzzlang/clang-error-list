
typedef unsigned char BOOL;

@interface NSObject
@end

@interface NSNumber : NSObject
+ (NSNumber *)numberWithChar:(char)value;
@end

@interface NSArray : NSObject
+ (id)arrayWithObjects:(const id [])objects count:(unsigned long)cnt;
@end

void fixes(void) {
  id arr = @[
    17, // expected-error{{numeric literal must be prefixed by '@' in a collection}}
  ];
}
