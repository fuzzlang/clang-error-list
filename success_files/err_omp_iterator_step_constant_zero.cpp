
struct vector {
    int operator[](int index) { return 0; }
};

int main(int argc, char **argv) {
    vector *argcPtr = nullptr;

    #pragma omp task depend(iterator(vector *argc = nullptr:nullptr+2:0), in:argc) // omp45-error {{expected 'in', 'out', 'inout' or 'mutexinoutset' in OpenMP clause 'depend'}} omp50-error {{invalid operands to binary expression ('std::nullptr_t' and 'int')}} omp50-error {{iterator step expression 0 evaluates to 0}} omp51-error {{invalid operands to binary expression ('std::nullptr_t' and 'int')}} omp51-error {{iterator step expression 0 evaluates to 0}}
    {
        // Task code
    }

    return 0;
}
