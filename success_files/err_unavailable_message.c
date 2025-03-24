
#if __has_feature(attribute_availability_app_extension)
 __attribute__((availability(macosx_app_extension,unavailable)))
#ifndef TVOS
 __attribute__((availability(ios_app_extension,unavailable)))
#else
 __attribute__((availability(tvos_app_extension,unavailable)))
#endif
#endif

void f0(int); // expected-note {{'f0' has been explicitly marked unavailable here}}

void test(void) {
  f0(1); // expected-error {{'f0' is unavailable: not available on}}
}
