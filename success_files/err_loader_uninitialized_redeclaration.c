
int declaration_then_uninit_ok;
int declaration_then_uninit_ok __attribute__((loader_uninitialized));

int definition_then_uninit_rejected = 5;
int definition_then_uninit_rejected __attribute__((loader_uninitialized));
