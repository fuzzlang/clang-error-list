
void __attribute__((target("default"))) invalid_features(void);

//expected-error@+2 {{function declaration is missing 'target' attribute in a multiversioned function}}
//expected-warning@+1 {{unsupported 'hello_world' in the 'target' attribute string; 'target' attribute ignored}}
void __attribute__((target("hello_world"))) invalid_features(void);
