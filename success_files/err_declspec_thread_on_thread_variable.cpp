
__thread __declspec(thread) int a; // expected-error {{already has a thread-local storage specifier}}
