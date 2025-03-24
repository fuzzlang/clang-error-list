
#if DELETED
int main(int argc, char **argv) = delete; // expected-error {{'main' is not allowed to be deleted}}
#else
int main(int argc, char **argv) {
    return 0;
}
#endif
