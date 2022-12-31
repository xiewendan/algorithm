#include <iostream>
using namespace std;

#include "./base.h"
#include <stack>

int main(int argc, char **argv)
{
    // 构造函数
    stack<int> myStack;             // mystack：空
    stack<int> myStack1({4, 1, 8}); // myStack1：4,1,8
    // stack<int> myStack2(3, 8);

    // 增
    myStack.push(1); // myStack：1
    myStack.push(2); // myStack：1,2

    // 删
    myStack.pop(); // myStack：1

    // 查
    int nValue = myStack.top(); // nValue = 1
    // cout << nValue << endl;

    // 改

    // common function
    bool bEmpty = myStack.empty(); // bEmpty = false
    // cout << bEmpty << endl;
    int nSize = myStack.size(); // nSize = 1
    // cout << nSize << endl;
    stack<int> myStack4(myStack); // copy contructor
    stack<int> myStack5;          // myStack5：空
    // myStack.clear();
    myStack.swap(myStack5); // myStack：空, myStack5: 1

    while (!myStack5.empty())
    {
        cout << myStack5.top() << endl;
        myStack5.pop();
    }
}
