
void my_function() {
    float *array2;
    float v2ua;

    (void)(array2[v2ua]); // expected-error{{array subscript is not an integer}}
}
