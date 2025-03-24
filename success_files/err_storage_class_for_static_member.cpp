
struct ABC {
    static double b; // definition without storage class
};

// expected-error@* {{static data member definition cannot specify a storage class}}
extern double ABC::b = 1.0; // This line will produce the expected error
