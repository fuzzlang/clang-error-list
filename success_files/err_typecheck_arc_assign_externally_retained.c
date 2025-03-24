
#define EXT_RET __attribute__((objc_externally_retained))

@interface ObjCTy
@end

void test() {
    EXT_RET ObjCTy *e = 0;
    e = 0; // expected-error{{variable declared with 'objc_externally_retained' cannot be modified in ARC}}
}
