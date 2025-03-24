
// expected-error {{'pt_guarded_by' attribute takes one argument}}
int *pgb_field_args PT_GUARDED_BY(mu1);

class PT_GUARDED_BY(mu1) PGB { // \
  // expected-warning {{'pt_guarded_by' attribute only applies to non-static data members and global variables}}
};

void pgb_function() PT_GUARDED_BY(mu1); // \
  // expected-warning {{'pt_guarded_by' attribute only applies to}}

void pgb_function_params(int gv_lvar PT_GUARDED_BY(mu1)); // \
  // expected-warning {{'pt_guarded_by' attribute only applies to}}

void pgb_testfn(int y) {
  int *x PT_GUARDED_BY(mu1) = new int(0); // \
    // expected-warning {{'pt_guarded_by' attribute only applies to}}
  delete x;
}

// Legal attribute arguments
int *pgb_var_arg_1 PT_GUARDED_BY(muWrapper.mu);
int *pgb_var_arg_2 PT_GUARDED_BY(muDoubleWrapper.muWrapper->mu);
int *pgb_var_arg_3 PT_GUARDED_BY(muWrapper.getMu());
int *pgb_var_arg_4 PT_GUARDED_BY(*muWrapper.getMuPointer());
int *pgb_var_arg_5 PT_GUARDED_BY(&mu1);
int *pgb_var_arg_6 PT_GUARDED_BY(muRef);
int *pgb_var_arg_7 PT_GUARDED_BY(muDoubleWrapper.getWrapper()->getMu());
int *pgb_var_arg_8 PT_GUARDED_BY(muPointer);

// Illegal attribute arguments
int *pgb_var_arg_bad_1 PT_GUARDED_BY(1); // \
  // expected-warning {{'pt_guarded_by' attribute requires arguments whose type is annotated with 'capability' attribute; type here is 'int'}}
int *pgb_var_arg_bad_2 PT_GUARDED_BY("mu"); // \
  // expected-warning {{ignoring 'pt_guarded_by' attribute because its argument is invalid}}
int *pgb_var_arg_bad_3 PT_GUARDED_BY(muDoublePointer); // \
  // expected-warning {{'pt_guarded_by' attribute requires arguments whose type is annotated with 'capability' attribute; type here is 'Mutex **'}}
int *pgb_var_arg_bad_4 PT_GUARDED_BY(umu); // \
  // expected-warning {{'pt_guarded_by' attribute requires arguments whose type is annotated with 'capability' attribute}}

//-----------------------------------------//
//  Acquired After (aa)
//-----------------------------------------//

// FIXME: Would we like this attribute to take more than 1 arg?

#if !__has_attribute(acquired_after)
#error "Should support acquired_after attribute"
#endif

Mutex mu_aa ACQUIRED_AFTER(mu1);

Mutex aa_var_noargs __attribute__((acquired_after)); // \
