#include <iostream>
using namespace std;

#include "./base.h"

int main(){
    // 构造函数
    multiset<int> mySet;

    // 增
    mySet.insert(4);    // mySet：4
    mySet.insert(4);    // mySet：4,4
    mySet.insert(5);    // mySet：4,4,5
    mySet.insert(6);    // mySet：4,4,5,6
    mySet.insert(6);    // mySet：4,4,5,6,6

    // 删
    mySet.erase(4); // mySet：5,6,6

    multiset<int>::iterator it = mySet.find(6);
    mySet.erase(it);    // mySet：5,6

    // 查
    it = mySet.find(6);

    // 改：不能修改

    //=== common function
    bool bEmpty = mySet.empty();
    int nSize = mySet.size();
    multiset<int> mySet4(mySet);
    mySet.clear();
    mySet4.swap(mySet);

    // 递归
    for(multiset<int>::iterator it = mySet4.begin(); it != mySet4.end(); ++it){
        cout << *it << endl;
    }
}