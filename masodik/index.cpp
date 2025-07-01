#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t[] = {1,2,3,4,5};
    for(int i=0;i<(sizeof(t)/sizeof(t[0]));i++)
    {
        cout<<t[i]<<endl;
    }
    
    int i=5;

    std::cout << sizeof(i) << std::endl;
    std::cout << sizeof(t) << std::endl;
}