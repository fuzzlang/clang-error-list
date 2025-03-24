
#define SA(...) __attribute__((swift_async(__VA_ARGS__)))

SA(swift_private, 1) void e(int); // expected-error{{'swift_async' completion handler parameter must have block type returning 'void', type here is 'int'}}
