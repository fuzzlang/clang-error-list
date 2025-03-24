
typedef void func_type_lvalue() &; // expected-error{{pointer to function type 'func_type_lvalue' (aka 'void () &') cannot have '&' qualifier}}
typedef func_type_lvalue *func_type_lvalue_ptr; // expected-error{{pointer to function type 'func_type_lvalue' (aka 'void () &') cannot have '&' qualifier}}
