#include <iostream>

using namespace std;

class A{
public:
static void f(double){
    cout << "f(double)" <<endl;
}
void f(int){
    cout << "f(int)" << endl;
}
};

int main()
{
    const A a;
    int i = 3;
    a.f(i);
}