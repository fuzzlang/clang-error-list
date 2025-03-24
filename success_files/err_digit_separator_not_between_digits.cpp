
int main() {
    int b = 0'xff; // expected-error {{digit separator cannot appear at end of digit sequence}} expected-error {{suffix 'xff' on integer}}
    return 0;
}
