
void h(int i, int j = 2, int k = 3, 
        int l, // expected-error {{missing default argument on parameter 'l'}}
        int,   // expected-error {{missing default argument on parameter}}
        int n);// expected-error {{missing default argument on parameter 'n'}}
