
typedef void (func_type)(void);

func_type array_funcs[10]; /* expected-error {{'array_funcs' declared as array of functions of type 'func_type' (aka 'void (void)')}} */
