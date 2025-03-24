
void streaming_decl() __arm_streaming;

void non_streaming_def(void (*streaming_fn_ptr)(void) __arm_streaming,
                       void (*streaming_compatible_fn_ptr)(void) __arm_streaming_compatible) {
    streaming_decl(); // expected-error {{call to a streaming function requires 'sme'}}
}
