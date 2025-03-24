
__declspec(naked) void f(void) {} // expected-error{{'__declspec' attributes are not enabled; use '-fdeclspec' or '-fms-extensions' to enable support for __declspec attributes}}
