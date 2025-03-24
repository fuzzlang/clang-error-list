
struct A {};
typedef struct A *MPI_Datatype;

int wrong2(void *buf, MPI_Datatype datatype)
    __attribute__(( pointer_with_type_tag(mpi,0,7) )); // expected-error {{attribute parameter 2 is out of bounds}}
