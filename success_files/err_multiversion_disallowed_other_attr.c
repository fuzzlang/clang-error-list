
__attribute__((target_clones("sme2")))
void cannot_work_clones(void) __arm_streaming {}

__attribute__((target("sme2")))
void just_fine_streaming(void) __arm_streaming {}

__attribute__((target_version("sme2")))
void just_fine(void) { 
    just_fine_streaming(); 
}

__attribute__((target_version("default")))
void just_fine(void) {}

__arm_locally_streaming
__attribute__((target_version("sme2")))
void incompatible_locally_streaming(void) {}
