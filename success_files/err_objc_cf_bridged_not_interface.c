
typedef struct __attribute__((objc_bridge(NSTesting))) __CFError *CFTestingRef; // expected-note {{declared here}}

@class NSString;

id Test1(CFTestingRef cf) {
  return (NSString *)cf; // expected-error {{CF object of type 'CFTestingRef' (aka '__CFError *') is bridged to 'NSTesting', which is not an Objective-C class}} \
                         // expected-error {{cast of C pointer type 'CFTestingRef' (aka '__CFError *') to Objective-C pointer type 'NSString *' requires a bridged cast}} \
                         // expected-note {{use __bridge to convert directly (no change in ownership)}} \
                         // expected-note {{use __bridge_transfer to transfer ownership of a +1 'CFTestingRef' (aka '__CFError *') into ARC}}
}
