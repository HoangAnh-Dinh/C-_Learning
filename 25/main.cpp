#include <iostream>
#include <string>
using namespace std;

struct S
{
int a;
char b;
string c;
double d;
};

union U
{
int a;
char b;
string c;
double d;
};

int main() {
    cout << "sizeof(struct S): " << sizeof(S) << endl;
    cout << "sizeof(union U): " << sizeof(U) << endl;
    
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(char): " << sizeof(char) << endl;
    cout << "sizeof(string): " << sizeof(string) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;

    return 0;
}
