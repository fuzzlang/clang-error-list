
struct IncompleteTy;

struct IncompleteTy IncA, IncB, IncC; // expected-error 3{{tentative definition has type 'struct IncompleteTy' that is never completed}}
