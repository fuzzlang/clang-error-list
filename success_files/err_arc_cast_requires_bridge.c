
typedef struct __attribute__ ((objc_bridge(NSError))) __CFErrorRef * CFErrorRef; // expected-note 5 {{declared here}}

typedef struct __attribute__ ((objc_bridge(MyError))) __CFMyErrorRef * CFMyErrorRef; // expected-note 1 {{declared here}}

typedef struct __attribute__((objc_bridge(NSDictionary))) __CFDictionary * CFDictionaryRef;

typedef struct __attribute__((objc_bridge(NSTesting))) __CFError *CFTestingRef; // expected-note {{declared here}}

@interface I
@end

@protocol P1 @end
@protocol P2 @end
@protocol P3 @end
@protocol P4 @end
@protocol P5 @end

@interface NSError<P1, P2, P3> @end // expected-note 5 {{declared here}}
@interface MyError : NSError @end // expected-note 1 {{declared here}}

@class NSString;

typedef CFErrorRef CFErrorRef1;
typedef CFErrorRef1 CFErrorRef2; // expected-note 2 {{declared here}}

void Test2(CFErrorRef2 cf) {
    (void)(NSString *)cf; // expected-error {{cast of C pointer type 'CFErrorRef2' (aka '__CFErrorRef *') to Objective-C pointer type 'NSString *' requires a bridged cast}} \
                          // expected-note {{use __bridge to convert directly (no change in ownership)}} \
                          // expected-note {{use __bridge_transfer to transfer ownership of a +1 'CFErrorRef2' (aka '__CFErrorRef *') into ARC}}
}
