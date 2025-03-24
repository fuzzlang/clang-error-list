
namespace error_example {
  void test_function() {
    int x = 5;
    __builtin_eh_return_data_regno(x); // both-error {{argument to '__builtin_eh_return_data_regno' must be a constant integer}}
  }
}
