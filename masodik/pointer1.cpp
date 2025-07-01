#include <iostream>
#include <ostream>
#include "x.h"


using namespace std;

void fahrtocels(int a)
{
    for(int i=-100;i<a;i+=10)
    {
        cout<<"fahr: "<< i<<" to cels: "<< (( i - 32) * 5 ) / 9 << endl;
    }
    a+=23423423;
}


int main()
{
    XX::x();            //[\] spec char
    cout<<"Egy x és no [\\n] ";
    cout<<"masodik sor";
    int a=50;
    fahrtocels(a);
    cout<<a<<endl;
    int* p=&a;
    *p=100;
    cout<<a<<endl;

}