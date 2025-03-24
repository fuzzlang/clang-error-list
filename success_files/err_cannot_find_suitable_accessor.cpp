
struct StructWithProperty {
    __declspec(property(get=GetV)) int V1;
    __declspec(property(put=SetV)) int V2;
    __declspec(property(get=GetV_NotExist, put=SetV)) int V4; // No getter defined
    int GetV() { return 123; }
    void SetV(int i) {}
};

void TestProperty() {
    StructWithProperty sp;
    int j = sp.V4; // expected-error{{no member named 'GetV_NotExist' in 'StructWithProperty'}} expected-error{{cannot find suitable getter for property 'V4'}}
}
