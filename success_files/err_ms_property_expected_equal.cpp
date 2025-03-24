
__declspec(property(set)) int V2; // expected-error {{putter for property must be specified as 'put', not 'set'}} expected-error {{expected '=' after 'set'}}
