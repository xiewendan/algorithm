#include <iostream>
using namespace std;

#include "./base.h"

int main()
{
    // 构造函数
    map<char, int> myMap;

    // 增
    myMap.insert(pair<char, int>('a', 100)); // myMap：a:100
    myMap.insert(make_pair('b', 200));       // myMap：a:100,b:200
    myMap.insert(make_pair('c', 300));       // myMap：a:100,b:200,c:300
    myMap.insert(make_pair('d', 400));       // myMap：a:100,b:200,c:300,d:400
    myMap.insert(make_pair('f', 500));       // myMap：a:100,b:200,c:300,d:400,f:500
    myMap.insert(make_pair('g', 600));       // myMap：a:100,b:200,c:300,d:400,f:500,g:600
    myMap.insert(make_pair('h', 700));       // myMap：a:100,b:200,c:300,d:400,f:500,g:600,h:700
    myMap['i'] = 800;                        // myMap：a:100,b:200,c:300,d:400,f:500,g:600,h:700,i:800


    // 删
    myMap.erase('f');// myMap：a:100,b:200,c:300,d:400,g:600,h:700,i:800

    // 查
    map<char, int>::iterator it = myMap.find('g'); // it指向g，it->first='g', it->second=600
    int nValue = myMap['h']; // nValue = 700

    // 改
    myMap['h'] = 800;// myMap：a:100,b:200,c:300,d:400,g:600,h:800,i:800
    // common function
    bool bEmpty = myMap.empty();
    int nSize = myMap.size();
    map<char, int> myMap4(myMap);
    myMap.clear();
    myMap4.swap(myMap);

    for (map<char, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << it->first << "," << it->second << endl;
    }
}