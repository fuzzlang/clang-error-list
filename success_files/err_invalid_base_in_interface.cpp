
// expected-error@+1 {{interface type cannot inherit from non-public interface 'I1'}}
__interface I1 {};

__interface I5 : private I1 {};
