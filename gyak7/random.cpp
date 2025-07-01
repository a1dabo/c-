#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    string number_name[10]= { 
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "Greater than 9"
    };
    
    int a,b;
    std::cin>>a>>b;
   
    
    for(int i=a;i<b;i++)
    {
        if (i<10) {
        std::cout<<number_name[i]<<std::endl;
        }
        else {
            if (i%2==0) {
            std::cout<<"even"<<std::endl;
            }
            else {
            std::cout<<"odd"<<std::endl;
            }
        }
    }
    
    return 0;
}