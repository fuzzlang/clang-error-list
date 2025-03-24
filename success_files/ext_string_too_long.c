
int main() {
    char* long_string = "sdjflksdjf lksdjf skldfjsdkljflksdjf kldsjflkdsj fldks jflsdkjfds\
    sdjflksdjf lksdjf skldfjsdkljflksdjf kldsjflkdsj fldks jflsdkjfds \
    sdjflksdjf lksdjf skldfjsdkljflksdjf kldsjflkdsj fldks jflsdkjfds \
    sdjflksdjf lksdjf skldfjsdkljflksdjf kldsjflkdsj fldks jflsdkjfds \
    sdjflksdjf lksdjf skldfjsdkljflksdjf kldsjflkdsj fldks jflsdkjfds \
    sdjflksdjf lksdjf skldfjsdkljflksdjf kldsjflkdsj fldks jflsdkjfds \
    sdjflksdjf lksdjf skldfjsdkljflksdjf kldsjflkdsj fldks jflsdkjfds \
    sdjflksdjf lksdjf skldfjsdkljflksdjf kldsjflkdsj fldks jflsdkjfds \
    sdjflksdjf lksdjf skldfjsdkljflksdjf kldsjflkdsj fldks jflsdkjfds \
    sdjflksdjf lksdjf skldfjsdkljflksdjf kldsjflkdsj fldks jflsdkjfds"; // expected-error{{string literal of length 845 exceeds maximum length 509 that C90 compilers are required to support}}
    return 0;
}
