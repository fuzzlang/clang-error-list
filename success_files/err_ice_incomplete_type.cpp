
extern struct Incomplete incomplete;

int main() {
    auto new2 = new int[1][incomplete]; // expected-error {{incomplete}}
}
