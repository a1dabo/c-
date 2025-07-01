#include <iostream>
#include "proba1.h"

int ccount(std::string* input)
{
    int i=0;
    while ((char)&input[i]!='\0')
    {
        i++;
    }
    *input="granat";
    return i;
}

int main()
{
    int a=10;
    proba1<int> a1(a);
    a=10000;
    std::cout<< a1.get() << std::endl;
    a1.rew();
    std::cout<< a1.get() << std::endl;
    std::string szo="beka";
    std::cout<< ccount(&szo) <<std::endl;
    std::cout<< szo << std::endl;
}