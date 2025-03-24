
struct A {};
typedef struct A *MPI_Datatype;

int wrong10(double buf, MPI_Datatype type) 
    __attribute__((pointer_with_type_tag(mpi, 1, 2))); // expected-error {{'pointer_with_type_tag' attribute only applies to pointer arguments}}
