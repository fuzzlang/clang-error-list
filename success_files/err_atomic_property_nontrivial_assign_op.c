
class TCPPObject {
public:
    TCPPObject(const TCPPObject& inObj);
    TCPPObject();
    ~TCPPObject();
    TCPPObject& operator=(const TCPPObject& inObj) const; // expected-note {{'operator=' declared here}}

    void* Data();

private:
    void* fData;
};

typedef const TCPPObject& CREF_TCPPObject;

@interface TNSObject
@property (assign, readwrite, nonatomic) CREF_TCPPObject cppObjectNonAtomic;
@property (assign, readwrite) CREF_TCPPObject cppObjectAtomic; // expected-error{{atomic property of reference type 'CREF_TCPPObject' (aka 'const TCPPObject &') cannot have non-trivial assignment operator}}
@property (assign, readwrite, nonatomic) const TCPPObject& cppObjectDynamic;
@end

@implementation TNSObject
@synthesize cppObjectNonAtomic;
@synthesize cppObjectAtomic; 
@dynamic cppObjectDynamic;
@end
