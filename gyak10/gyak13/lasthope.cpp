#include <iostream>
#include <vector>
#include <algorithm>

template <class Cont, class Predicate = std::less<>, class T = typename Cont::value_type>
class vdmtest
{

    Cont &cont;
    Predicate pred;

public:
    vdmtest(Cont &cnt, Predicate p = Predicate()) : cont(cnt), pred(p) {}

    void sort()
    {
        std::sort(cont.begin(), cont.end(), pred);
    }

    void printAll()
    {
        for (auto it = cont.begin(); it != cont.end(); it++)
        {
            std::cout << *it << ' ';
        }
        std::cout << std::endl;
    }
};

int main()
{
    std::vector<int> vint = {3, 2, 45, 5, 34, 543, 5, 6};
    vdmtest sanyi(vint);
    sanyi.printAll();
    sanyi.sort();
    sanyi.printAll();
}