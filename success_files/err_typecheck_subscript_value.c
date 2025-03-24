
typedef __vector_quad vq_t;

vector unsigned char testVQOperators3(int *ptr) {
    __vector_quad *vqp = (__vector_quad *)ptr;
    __vector_quad vq1 = *(vqp + 0);
    __vector_quad vq2 = *(vqp + 1);
    __vector_quad vq3 = *(vqp + 2);
    vq2 = vq3;
    return vq2[1]; // expected-error {{subscripted value is not an array, pointer, or vector}}
}
