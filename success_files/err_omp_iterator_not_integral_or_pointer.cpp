
typedef void *omp_depend_t;

class vector {
public:
    int operator[](int index) { return 0; }
};

int main(int argc, char **argv) {
    vector vec;

    #pragma omp task depend(iterator(vector argc = 0:2):argc) // omp45-error {{expected 'in', 'out', 'inout' or 'mutexinoutset' in OpenMP clause 'depend'}} omp50-error {{expected integral or pointer type as the iterator-type, not 'vector'}} omp50-error {{expected depend modifier(iterator) or 'in', 'out', 'inout', 'mutexinoutset' or 'depobj' in OpenMP clause 'depend'}} omp50-error {{expected ','}} omp51-error {{expected integral or pointer type as the iterator-type, not 'vector'}} omp51-error {{expected depend modifier(iterator) or 'in', 'out', 'inout', 'mutexinoutset', 'depobj' or 'inoutset' in OpenMP clause 'depend'}} omp51-error {{expected ','}}
    {
        // Task body
    }

    return 0;
}
