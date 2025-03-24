
int main() {
    for (; int n = ({continue; 0;});) {} // expected-error {{cannot jump from this continue statement to the loop increment; jump bypasses initialization of loop condition variable}}
    return 0;
}
