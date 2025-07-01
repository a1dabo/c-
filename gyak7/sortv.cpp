#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int *> vecp;
    int a[] = {5, 4, 3, 2, 1};
    for (size_t i = 0; i < 5; i++)
    {
        vecp.push_back(&a[i]);
    }

    for (auto &n : vecp)
    {
        std::cout << *n << ' ';
    }
    std::cout << std::endl;

    std::sort(vecp.begin(), vecp.end(), [](int *lhs, int *rhs)
              { return *lhs < *rhs; });

    for (auto &n : vecp)
    {
        std::cout << *n << ' ';
    }
}