
using size_t = decltype(sizeof(int));

// Acceptable parameter declarations
char operator "" _a(const char *); 
char operator "" _a(const char []); 
char operator "" _a(unsigned long long); 
char operator "" _a(long double); 
char operator "" _a(char); 
char operator "" _a(const volatile char); 
char operator "" _a(wchar_t); 
char operator "" _a(char16_t); 
char operator "" _a(char32_t); 
char operator "" _a(const char *, size_t); 
char operator "" _a(const wchar_t *, size_t); 
char operator "" _a(const char16_t *, size_t); 
char operator "" _a(const char32_t *, size_t); 
char operator "" _a(const char [32], size_t); 

// Unacceptable parameter declarations
char operator "" _a(const char *, size_t = 0); // expected-error {{default argument}}
