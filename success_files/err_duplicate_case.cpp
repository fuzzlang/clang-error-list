
int main() {
    switch (0) {
        case 0: 
            // First case with value 0
            break;
        case 0: // expected-error {{duplicate case value '0'}}
            // Duplicate case with value 0
            break;
    }
    return 0;
}
