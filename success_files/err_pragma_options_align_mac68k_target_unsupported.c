
/* expected-error {{mac68k alignment pragma is not supported}} */ 
#pragma options align=mac68k

int main() {
    return 0;
}
