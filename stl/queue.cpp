#include <iostream>
using namespace std;

#include <queue>

int main()
{
    // 构造函数
    queue<int> myq({4, 1, 8}); // myq：4,1,8

    // 增
    myq.push(5); // myq：4,1,8,5
    myq.push(6); // myq：4,1,8,5,6

    // 删
    myq.pop(); // myq：1,8,5,6

    // 查
    int nFront = myq.front(); // nFront = 1
    int nBack = myq.back();   // nBack = 6
    // cout << nFront << endl;
    // cout << nBack << endl;

    // 改

    // // common function
    bool bEmpty = myq.empty(); // bEmpty = false
    cout << bEmpty << endl;
    int nSize = myq.size(); // nSize = 4
    cout << nSize << endl;
    // myq.clear();
    queue<int> myq4(myq); // myq4：1,8,5,6
    queue<int> myq5;
    myq5.swap(myq); // myq5：1,8,5,6  myq：空
    while (!myq5.empty())
    {
        cout << myq5.front() << endl;
        myq5.pop();
    }
}