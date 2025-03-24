
namespace std {
    class source_location {
    public:
        struct __impl {
            const char *_M_file_name;
            const char *_M_function_name;
            int _M_line;
            // Intentionally malformed: Missing _M_column and extra field
            int _M_some_other_field; 
        };

        static constexpr source_location current(const char* file = __builtin_FILE(),
                                                 const char* function = __builtin_FUNCTION(),
                                                 int line = __builtin_LINE()) noexcept {
            return source_location(file, function, line);
        }

    private:
        constexpr source_location(const char* file, const char* function, int line)
            : _M_impl{file, function, line, 0} {}

        __impl _M_impl;
    };
}

void test() {
    auto test2b = __builtin_source_location(); // expected-error {{'std::source_location::__impl' must be standard-layout and have only two 'const char *' fields '_M_file_name' and '_M_function_name', and two integral fields '_M_line' and '_M_column'}}
}
