#include <iostream>
#include <vector>

#include "ctvtor.h"

    void print(std::vector<int>& inv)
    {
        for (size_t i = 0; i < inv.size(); i++)
        {
            std::cout<<inv[i]<<' ';
        }
        std::cout<<std::endl;
    }

int main()
{
    int alma[]={5,4,3,2,1};
    ctvtor<int> ctvtor;
    std::vector<int> inv={6,7,8,9,10};

    ctvtor.append(alma,sizeof alma/sizeof alma[0]);

    ++ctvtor;

    std::cout<<alma[0]<<std::endl;
    std::cout<<ctvtor.get(0)<<std::endl;

    ctvtor.rew();
    std::cout<<alma[0]<<std::endl;
    std::cout<<ctvtor.get(0)<<std::endl;

    ctvtor++;

    std::cout<<alma[0]<<std::endl;
    std::cout<<ctvtor.get(0)<<std::endl;

    ctvtor.rew();
    
    std::cout<<alma[0]<<std::endl;
    std::cout<<ctvtor.get(0)<<std::endl;

    ctvtor+=10;

    std::cout<<alma[0]<<std::endl;
    std::cout<<ctvtor.get(0)<<std::endl;

    ctvtor.rew();

    std::cout<<alma[0]<<std::endl;
    std::cout<<ctvtor.get(0)<<std::endl;

    ctvtor.append(inv);

    std::cout<<inv[1]<<std::endl;
    std::cout<<ctvtor.get(6)<<std::endl;

    inv[1]=2222;
    
        std::cout<<inv[1]<<std::endl;
    std::cout<<ctvtor.get(6)<<std::endl;

    ctvtor.rew();

        std::cout<<inv[1]<<std::endl;
    std::cout<<ctvtor.get(6)<<std::endl;

    inv[3]=5646;

    
    ctvtor.sort();

    print(inv);
    ctvtor.print();

}