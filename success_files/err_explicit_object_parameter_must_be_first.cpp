
auto l4 = [](int, this auto){}; // expected-error {{an explicit object parameter can only appear as the first parameter of the lambda}}
