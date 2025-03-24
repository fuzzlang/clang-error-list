
union { char x[]; } r = {0}; /* gnu-warning {{flexible array member 'x' in a union is a GNU extension}} 
                                microsoft-warning {{flexible array member 'x' in a union is a Microsoft extension}} 
                              */
struct _name1 {
  int a;
  union {
    int b;
    char x[]; /* gnu-warning {{flexible array member 'x' in a union is a GNU extension}} 
                 microsoft-warning {{flexible array member 'x' in a union is a Microsoft extension}} 
               */
  };
} name1 = {
  10,
  42,        /* initializes "b" */
};

struct _name1i {
  int a;
  union {
    int b;
    char x[]; /* gnu-warning {{flexible array member 'x' in a union is a GNU extension}} 
                 microsoft-warning {{flexible array member 'x' in a union is a Microsoft extension}} 
               */
  };
} name1i = {
  .a = 10,
  .b = 42,
};

/* Initialization of flexible array in a union is never allowed. */
struct _name2 {
  int a;
  union {
    int b;
    char x[]; /* gnu-warning {{flexible array member 'x' in a union is a GNU extension}} 
                 microsoft-warning {{flexible array member 'x' in a union is a Microsoft extension}} 
               */
  };
} name2 = {
  12,
  13,
  { 'c' },   /* c-warning {{excess elements in struct initializer}} 
                cpp-error {{excess elements in struct initializer}} 
              */
};

/* Initialization of flexible array in a union is never allowed. */
struct _name2i {
  int a;
  union {
    int b;
    char x[]; /* gnu-warning {{flexible array member 'x' in a union is a GNU extension}} 
                 microsoft-warning {{flexible array member 'x' in a union is a Microsoft extension}} 
                 stock-note {{initialized flexible array member 'x' is here}} 
               */
  };
} name2i = {
  .a = 12,
  .b = 13,      /* stock-note {{previous initialization is here}} */
  .x = { 'c' }, /* stock-error {{initialization of flexible array member is not allowed}} */
};
