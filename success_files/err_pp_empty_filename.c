
#pragma include_alias("", "foo.h")  // expected-error {{empty filename}}

int main() {
    return 0;
}
