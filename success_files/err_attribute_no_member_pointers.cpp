
struct cls {
    int m;
};

int main() {
    char * cls::* __uptr wrong2 = &cls::m; // expected-error {{'__uptr' attribute cannot be used with pointers to members}}
    return 0;
}
