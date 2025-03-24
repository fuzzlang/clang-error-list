
__declspec(property(get=GetV,put=SetV,get=GetV)) int V12; // expected-error {{property declaration specifies 'get' accessor twice}}
