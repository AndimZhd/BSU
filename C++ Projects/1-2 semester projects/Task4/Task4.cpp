#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <array>
const int n = 20;
template<typename T>
bool sumOfElements(T container)
{
    for (int i = 0; i < (container.size() / 2); i++)
        if (container[i] != container[container.size() - i - 1])
            return false;
    return true;
}

int main()
{
    std::vector<int> v(2, 10);
    if(sumOfElements(v))
        std::cout << "result : True"<< std::endl;
    else
        std::cout << "result : False" << std::endl;
    std::list<int> l(2, 5);
    if (sumOfElements(l))
        std::cout << "result : True" << std::endl;
    else
        std::cout << "result : False" << std::endl;
    std::set<int> s = { 1, 2, 3, 4, 5, 6, 7, 8 };
    if (sumOfElements(s))
        std::cout << "result : True" << std::endl;
    else
        std::cout << "result : False" << std::endl;
    std::array<int, n> a = {2, 4, 5, 4, 2};
    if (sumOfElements(v))
        std::cout << "result : True" << std::endl;
    else
        std::cout << "result : False" << std::endl;
    return 0;
}
