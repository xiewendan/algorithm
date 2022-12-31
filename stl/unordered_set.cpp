#include <iostream>
using namespace std;

#include "./base.h"

int main()
{
    // 构造函数
    unordered_set<string> mySet = {"red", "green", "blue"}; // mySet：red, green, blue
    unordered_set<string> mySet1({"red", "green", "blue"}); // mySet1：red, green, blue
    unordered_set<string> mySet3(mySet);                    // mySet3：red, green, blue

    // 增
    mySet.insert("yellow"); // mySet: red, green, blue, yellow
    vector<string> vec({"purple", "pink"});
    mySet.insert(vec.begin(), vec.end()); // mySet：red, green, blue, yellow, purple, pink

    // 删
    mySet.erase("yellow");

    // 查
    unordered_set<string>::const_iterator it = mySet.find("green");
    if (it != mySet.end())
    {
        // cout << *it << endl;
    }

    // 改：不可改

    // common function
    bool bEmpty = mySet.empty();
    int nSize = mySet.size();
    unordered_set<string> mySet4(mySet);
    mySet.clear();
    mySet4.swap(mySet);

    // 遍历
    for (unordered_set<string>::iterator it = mySet4.begin(); it != mySet4.end(); ++it)
    {
        cout << *it << endl;
    }

    // special function
    cout << "==========special function" << endl;
    cout << mySet.load_factor() << endl;
    cout << mySet.bucket("red") << endl;
    cout << mySet.bucket_count() << endl;
}