
#if !__has_extension(pragma_clang_attribute_namespaces)
#error
#endif

#pragma clang attribute Misc. () // expected-error{{namespace can only apply to 'push' or 'pop' directives}} expected-note {{omit the namespace to add attributes to the most-recently pushed attribute group}}
