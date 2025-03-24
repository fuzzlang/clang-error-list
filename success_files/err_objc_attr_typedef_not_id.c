
typedef void * __attribute__ ((objc_bridge(NSURL))) CFURLRef;  // expected-error {{parameter of 'objc_bridge' attribute must be 'id' when used on a typedef}}
