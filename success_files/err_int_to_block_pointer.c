
int (*FP)();
int (^IFP) ();
int (^II) (int);

int main(void) {
    int * const (^IPCC) () = 0;
    int * const (^IPCC1) () = IPCC;
    IPCC1 = 1; // expected-error {{invalid block pointer conversion assigning to 'int *const (^)()' from 'int'}}
}
