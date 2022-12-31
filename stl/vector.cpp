#include <iostream>

using namespace std;

#include "./base.h"

int main()
{
    cout << "Hello, world!" << endl;

    //=== 构造函数
    vector<int> vec;             // 空
    vector<int> vec1({4, 1, 8}); // 418
    vector<int> vec2(3, 8);      // 888
    vector<int> vec3(vec1);      // 418

    // 增
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);

    // 删
    vec.pop_back();

    // 查
    cout << vec[3] << endl;    // no range check   ok。 no use this function， no safe
    cout << vec.at(1) << endl; // throw range_error exception of out of range

    // 改
    vec[3] = 11;    // no range check, so dangerous, vec[3] = 11。 no use this function. no safe
    vec.at(1) = 10; // vec[1] = 10

    //=== common member functions of all container
    // vec:{4,1,8}
    vector<int> vec4(vec);       // copy contructor，vec4：418，vec：418
    bool bIsEmpty = vec.empty(); // bIsEmpty = false
    int nSize = vec.size();      // nSize = 3
    vec.clear();                 // remove all item in vec;  vec：空
    vec4.swap(vec);              // swap two vec4，vec4：空，vec：418

    // 遍历
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << endl;
    }
}