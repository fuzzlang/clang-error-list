
__attribute__((reqd_work_group_size(8, 16, 32))) void kernel8(){} // expected-error {{attribute 'reqd_work_group_size' can only be applied to an OpenCL kernel}}
