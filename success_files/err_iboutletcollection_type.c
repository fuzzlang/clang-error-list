objc
@class NSObject;

@interface I {
    __attribute__((iboutletcollection(I))) id ivar1;
    __attribute__((iboutletcollection(id))) id ivar2;
    __attribute__((iboutletcollection())) id ivar3;
    __attribute__((iboutletcollection)) id ivar4;
}

@property (nonatomic, retain) __attribute__((iboutletcollection(I))) id prop1;
@property (nonatomic, retain) __attribute__((iboutletcollection(id))) id prop2;
@property (nonatomic, retain) __attribute__((iboutletcollection())) id prop3;
@property (nonatomic, retain) __attribute__((iboutletcollection)) id prop4;

@end

typedef void *PV;

@interface BAD {
    __attribute__((iboutletcollection(PV))) id ivar3; // expected-error {{invalid type 'PV' (aka 'void *') as argument of iboutletcollection attribute}}
}
@end
