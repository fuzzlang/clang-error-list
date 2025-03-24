
class PR27122 {
public:
    static void regularEnableIf(int arg1) {}
};

int main() {
    PR27122::regularEnableIf(); // expected-error{{too few arguments}}
    return 0;
}
