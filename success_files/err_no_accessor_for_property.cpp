
struct StructWithProperty {
    __declspec(property(get=GetV)) int V1;
    __declspec(property(put=SetV)) int V2; // no getter defined

    int GetV() { return 123; }
    void SetV(int i) {}
};

void TestProperty() {
    StructWithProperty sp;
    int i = sp.V2; // expected-error{{no getter defined for property 'V2'}}
}
