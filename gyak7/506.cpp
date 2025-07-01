#include <iostream>

// Két változó értékeinek cseréje (nem pointercímeké!)
template <class T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Két pointer címének cseréje
template <class T>
void swappoint(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

struct Point
{
    int x, y;
};

int main()
{
    char a = 'a';
    char b = 'b';

    std::cout << "a b|" << a << ' ' << b << std::endl;
    swap(a, b);
    std::cout << "b a|" << a << ' ' << b << std::endl;
    swappoint(&a, &b);
    std::cout << "a b|" << a << ' ' << b << std::endl;
    int x = 7;
    int y = 4;
    swap(x, y);
    std::cout << x << y << std::endl;
    double d = 3.4;
    double e = 1.2;
    swap(d, e);
    std::string h = "Hello";
    std::string w = "World";

    swap(h, w);
    std::cout << h << ' ' << w << std::endl;
    std::cout << d << ' ' << e << std::endl;

    Point x1;
    x1.x = 1;
    x1.y = 1;
    Point x2;
    x2.x = 2;
    x2.y = 2;

    std::cout << "before x1: " << x1.x << ' ' << x1.y << " before x2: " << x2.x << ' ' << x2.y << std::endl;
    swap(x1, x2);
    std::cout << "after x1: " << x1.x << ' ' << x1.y << " after x2: " << x2.x << ' ' << x2.y << std::endl;
}