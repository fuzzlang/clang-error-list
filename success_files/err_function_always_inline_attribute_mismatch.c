
#define __ai __attribute__((always_inline))

__ai void inlined_fn(void) {}
__ai void inlined_fn_streaming_compatible(void) __arm_streaming_compatible {}
__ai void inlined_fn_streaming(void) __arm_streaming {}

void caller(void) {
    inlined_fn();  
    inlined_fn_streaming_compatible();  
    inlined_fn_streaming(); // expected-error {{always_inline function 'inlined_fn_streaming' and its caller 'caller' have mismatching streaming attributes}}
}
