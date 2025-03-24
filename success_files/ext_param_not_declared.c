
void f1(x, y) 
{
    int result = x + y; // expected-error 2{{was not declared, defaults to 'int'; ISO C99 and later do not support implicit int}}
}
