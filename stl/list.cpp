#include <iostream>
using namespace std;

#include "./base.h"

int main()
{
    // 构造函数
    list<int> lis;             // lis：空
    list<int> lis1({4, 1, 8}); // list1：4,1,8
    list<int> lis2(3, 8);      // list1：8,8,8
    list<int> lis3(lis);       // lis3：空

    // 增
    lis.push_back(4);                                         // lis：4
    lis.push_back(1);                                         // lis：4,1
    lis.push_back(8);                                         // lis：4,1,8
    list<int>::iterator it = find(lis.begin(), lis.end(), 4); // it指向4
    lis.insert(it, 6);                                        // it指向：4，lis：6,4,1,8

    // 删
    ++it;          // it指向1
    lis.erase(it); // 移除1，lis：6,4,8

    // 查
    it = find(lis.begin(), lis.end(), 4);

    // 改
    *it = 5; // lis：6,5,8

    //=== common function
    bool bEmpty = lis.empty();
    int nSize = lis.size();
    list<int> lis4(lis);
    lis.clear();
    lis4.swap(lis);

    // 递归遍历
    for (list<int>::iterator it1 = lis.begin(); it1 != lis.end(); ++it1)
    {
        cout << *it1 << endl;
    }
}