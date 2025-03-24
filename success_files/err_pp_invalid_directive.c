
# nope /* expected-error {{invalid preprocessing directive}} */

/* Invalid preprocessing directive case */
int main() {
    # 'a // expected-error {{invalid preprocessing directive}}
    return 0;
}
