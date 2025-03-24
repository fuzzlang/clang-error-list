
void f1(void) __attribute__((availability(shadermodel, introduced = 6.0, environment=""))); // expected-error {{expected an environment name, e.g., 'compute'}}
