
__attribute__((availability(shadermodel, introduced = 6.5)))
float fx(float);

float also_alive(float f) {
    // expected-error@#also_alive_fx_call {{'fx' is only available on Shader Model 6.5 or newer}}
    // expected-note@#fx {{'fx' has been marked as being introduced in Shader Model 6.5 here, but the deployment target is Shader Model 6.0}}
    float A = fx(f); // #also_alive_fx_call
    return 0;
}
