
struct Example {
    short other_field : __CHAR_BIT__ * 2 + 1; /* expected-error-re {{width of bit-field 'other_field' ({{[0-9]+}} bits) exceeds the width of its type ({{[0-9]+}} bits)}} */
};
