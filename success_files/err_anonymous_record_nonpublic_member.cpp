
struct {
    class { 
        int anon_priv_field; // expected-error {{anonymous struct cannot contain a private data member}}  
    }; 
} myStruct;
