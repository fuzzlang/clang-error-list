
enum E2 { Five };

__arm_inout("za") enum E2 { Six }; // expected-error {{misplaced '__arm_inout'}}
