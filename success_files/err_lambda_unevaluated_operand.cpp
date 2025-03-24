
decltype([&arr]{}) *p; // expected-error {{lambda expression in an unevaluated operand}}
