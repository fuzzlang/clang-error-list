
typedef struct {
    S();
} DT; 

struct DT {   // expected-error {{definition of type 'DT' conflicts with typedef of the same name}} 
    DT();  
};
