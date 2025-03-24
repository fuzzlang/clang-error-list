
auto l3 = [](this auto...) { 
    // Code inside the lambda
}; // expected-error {{the explicit object parameter cannot be a function parameter pack}}
