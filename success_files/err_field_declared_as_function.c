
typedef void ytype();

typedef struct _zend_module_entry zend_module_entry;
struct _zend_module_entry {
    ytype globals_size; // expected-error {{field 'globals_size' declared as a function}}
};
