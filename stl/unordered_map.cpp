#include <iostream>
using namespace std;

#include "./base.h"

int main()
{
    // 构造函数
    unordered_map<char, string> myMap({{'S', "Sunday"}, {'M', "Monday"}}); // myMap： S:Sunday, M:Monday

    // 增
    myMap.insert(make_pair('T', "Tuesday")); // myMap： S:Sunday, M:Monday, T:Tuesday
    myMap['W'] = "Wednesday";                // myMap： S:Sunday, M:Monday, T:Tuesday, W:Wednesday

    // 删
    myMap.erase('W'); // myMap： S:Sunday, M:Monday, T:Tuesday

    // 查
    string szValue = myMap['T']; // szValue = Tuesday
    // cout << szValue << endl;

    // 改
    myMap['S'] = "Saturday"; // myMap： S:Saturday, M:Monday, T:Tuesday

    // common functions
    bool bEmpty = myMap.empty();
    int nSize = myMap.size();
    unordered_map<char, string> myMap4(myMap);
    myMap.clear();
    myMap.swap(myMap4);

    // 遍历
    for (unordered_map<char, string>::iterator it = myMap4.begin(); it != myMap4.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    // load factor, bucket, bucket_count
    cout << "======special function" << endl;
    cout << myMap.load_factor() << endl;
    cout << myMap.bucket('S') << endl;
    cout << myMap.bucket_count() << endl;
}