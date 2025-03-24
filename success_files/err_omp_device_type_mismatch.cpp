
#pragma omp declare target link(x) // expected-error {{'x' must not appear in both clauses 'to' and 'link'}}

void function1() {}
#pragma omp declare target to(function1) device_type(nohost) // omp45-error {{unexpected 'device_type' clause, only 'to' or 'link' clauses expected}} host5-note 3{{marked as 'device_type(nohost)' here}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}
void function2() { function1(); }
#pragma omp declare target to(function2) device_type(nohost) // omp45-error {{unexpected 'device_type' clause, only 'to' or 'link' clauses expected}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}
void function3() { function1(); } // host5-error {{function with 'device_type(nohost)' is not available on host}}
void function4() { function1(); } // host5-error {{function with 'device_type(nohost)' is not available on host}}
#pragma omp declare target to(function4) device_type(host) // omp45-error {{unexpected 'device_type' clause, only 'to' or 'link' clauses expected}} dev5-note 3 {{marked as 'device_type(host)' here}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}
void function5() { function1(); } // host5-error {{function with 'device_type(nohost)' is not available on host}}
#pragma omp declare target to(function5) // omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}
void function6() { function4(); } // dev5-error {{function with 'device_type(host)' is not available on device}}
#pragma omp declare target to(function6) device_type(nohost) // omp45-error {{unexpected 'device_type' clause, only 'to' or 'link' clauses expected}} host5-note 2 {{marked as 'device_type(nohost)' here}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}
void function7() { function4(); } // dev5-error {{function with 'device_type(host)' is not available on device}}
#pragma omp declare target to(function7) // omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}

#pragma omp declare target
void function8() { function3(); }
void function9() { function4(); } // dev5-error {{function with 'device_type(host)' is not available on device}}
void function10() { function6(); } // host5-error {{function with 'device_type(nohost)' is not available on host}}
void function11() { function9(); }
#pragma omp end declare target

void function12() { function3(); }
void function13() { function4(); }
void function14() { function6(); } // host5-error {{function with 'device_type(nohost)' is not available on host}}
void function15() { function9(); }

int MultiDeviceType;
#pragma omp declare target to(MultiDeviceType) device_type(any)    // omp45-error {{unexpected 'device_type' clause, only 'to' or 'link' clauses expected}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}
#pragma omp declare target to(MultiDeviceType) device_type(host)   // omp45-error {{unexpected 'device_type' clause, only 'to' or 'link' clauses expected}} omp5-error {{'device_type(host)' does not match previously specified 'device_type(any)' for the same declaration}} omp51-error {{'device_type(host)' does not match previously specified 'device_type(any)' for the same declaration}} omp52-error {{unexpected 'to' clause, use 'enter' instead}} omp52-error {{expected at least one 'enter', 'link' or 'indirect' clause}}
