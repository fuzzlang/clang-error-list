
// expected-error@+5 {{function declared 'void (void) __arm_streaming_compatible' was previously declared 'void (void) __arm_streaming', which has different SME function attributes}}
// expected-note@+3 {{previous declaration is here}}
// expected-cpp-error@+3 {{function declared 'void () __arm_streaming_compatible' was previously declared 'void () __arm_streaming', which has different SME function attributes}}
// expected-cpp-note@+1 {{previous declaration is here}}
void myFunction(void) __arm_streaming;
void myFunction(void) __arm_streaming_compatible { }
