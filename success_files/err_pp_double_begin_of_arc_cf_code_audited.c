
void testFunction() {
    #pragma clang arc_cf_code_audited begin
    #pragma clang arc_cf_code_audited begin // expected-error {{already inside '#pragma clang arc_cf_code_audited'}} expected-note {{#pragma entered here}}
    // Some code here
    #pragma clang arc_cf_code_audited end
}
