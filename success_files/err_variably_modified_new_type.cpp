
int* dependent_array_size() {
    return new int[10]; // Sample implementation
}

int main() {
    int v = 0;
    return new int[]{v...}; // expected-error {{cannot initialize}}
}

int *p0 = dependent_array_size();
int *p3 = dependent_array_size(1, 2, 3);
int *fail = dependent_array_size("hello"); // expected-note {{instantiation of}}
int (*const_fold)[12] = new int[3][&const_fold + 12 - &const_fold];
