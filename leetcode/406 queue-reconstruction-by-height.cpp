#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vecData({1,10,2,8});

    std::sort(vecData.begin(), vecData.end(), [](auto a, auto b) {
        return a < b;
    });

    for(int i = 0; i < vecData.size(); ++i)
    {
        std::cout << vecData[i] << std::endl;
    }

    return 1;
}