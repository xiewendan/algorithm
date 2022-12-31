#include <iostream>
using namespace std;

#include "./base.h"

int main()
{
    // 构造函数
    set<int> mySet; // mySet：空
    // set<int> mySet1({4, 1, 8}); // 不存在该方法
    // set<int> mySet2(3,8); // 不存在该方法
    set<int> mySet3(mySet); // mySet3：空

    // 增
    pair<set<int>::iterator, bool> ret;
    ret = mySet.insert(4);                 // ret.first指向4，ret.second = true表示插入成功
    ret = mySet.insert(1);                 // ret.first指向1，ret.second = true表示插入成功
    ret = mySet.insert(8);                 // ret.first指向8，ret.second = true表示插入成功
    ret = mySet.insert(8);                 // ret.first指向8，ret.second = false表示插入失败
    ret = mySet.insert(9);                 // ret.first指向8，ret.second = true表示插入成功
    set<int>::iterator it = mySet.find(4); // it指向4
    mySet.insert(it, 5);                   // mySet：1,4,5,8,9

    // 删
    mySet.erase(8); // mySet：1,4,5,9

    // 查
    it = mySet.find(4); // it指向4
    mySet.erase(it);    // mySet：1,5,9

    // 改：set内部的数据只能读，不能修改

    // common function for container
    bool bEmpty = mySet.empty(); // 是否空，bEmpty = false
    int nSize = mySet.size();    // nSize = 3
    set<int> mySet4(mySet);      // 复制构造函数
    mySet.clear();               // 清空
    mySet4.swap(mySet);          // 交换

    for (set<int>::iterator it = mySet4.begin(); it != mySet4.end(); ++it)
    {
        cout << *it << endl;
    }
}