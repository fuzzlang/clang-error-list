
__thread int t15; // expected-note {{previous definition is here}} 
extern int t15; // expected-error {{non-thread-local declaration of 't15' follows thread-local declaration}}
