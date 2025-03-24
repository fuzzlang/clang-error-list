
typedef struct NSString NSString;

void maybeString(const char *cstr) __attribute__((format_arg(1))); // expected-error {{function does not return string type}}
