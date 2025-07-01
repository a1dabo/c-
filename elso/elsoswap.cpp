#include <iostream>
#define ALMA 5

int swap(int &a,int &b);



int swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
    temp = a + b;
    return temp;
}

using namespace std;

int a=2120;

int main()
{
    int b = 5;
    int c;
    cout << "before swap a: " << a << " b: " << b<<"\n";
    c = swap(a, b);
    cout << "after swap a: " << a << " b: " << b <<" sum: " << c << endl;
    cout<<ALMA*3;
}