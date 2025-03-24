
template<int Index, typename... T>
using ErrorTypePackElement1 = __type_pack_element<Index, T...>; // expected-error{{may not be accessed at an out of bounds index}}

int main() {
    ErrorTypePackElement1<3, int, double> element; // This will cause the error due to out of bounds index
    return 0;
}
