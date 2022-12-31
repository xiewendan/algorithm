#include <iostream>
using namespace std;

#include "./base.h"

int main()
{
    // 构造函数
    deque<int> deq = {4, 1, 8}; // deq: 418
    deque<int> deq1({4, 1, 8}); // deq1: 4,1,8
    deque<int> deq2(3, 8);      // deq2: 8,8,8
    deque<int> deq3(deq);       // deq3: 4,1,8

    // 增
    deq.push_back(5);  // deq：4,1,8,5
    deq.push_front(6); // deq：6,4,1,8,5

    // 删
    deq.pop_back();  // deq：6,4,1,8
    deq.pop_front(); // deq：4,1,8

    // 查
    int nValue = deq.at(1); // deq：nValue = 1
    int nValue1 = deq[1];   // deq：nValue1 = 1

    // 改
    deq[1] = 10;    // deq：4,10,8
    deq.at(1) = 12; // deq；4,12,8

    //== common function
    bool bEmpty = deq.empty(); // bEmpty=false
    int nSize = deq.size();    // nSize = 3
    deque<int> deq4(deq);      // deq4：4,12,8
    deq.clear();               // deq：空
    deq4.swap(deq);            // deq：4,12,8  deq4：空

    for (deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    {
        cout << *it << endl;
    }
}