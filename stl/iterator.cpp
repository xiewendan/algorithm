#include <iostream>
using namespace std;

#include "./base.h"

int main()
{
    //===
    // 1 random access iterator: vector, deque, array
    vector<int> vec({0, 1, 2, 3, 4, 5, 6});
    vector<int>::iterator itr = vec.begin();

    itr = itr + 5;
    itr = itr - 4;

    // 2 bidirectional iterator：list, set, map
    list<int> lis({0, 1, 2, 3, 4, 5});
    list<int>::iterator itr1 = lis.begin();
    ++itr1;
    --itr1;
    // itr1 = itr1 + 5;

    // 3 forward iterator：unordered_set, unordered_map，forward_list
    unordered_set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    unordered_set<int>::iterator itr2 = mySet.begin();
    ++itr2;
    // --itr2; // error, no support

    // ===
    // const iterator
    unordered_map<string, string> myMap({{"name", "xjc"}, {"age", "19"}, {"sex", "male"}, {"h", "10"}});
    for (unordered_map<string, string>::const_iterator itr = myMap.begin(); itr != myMap.end(); ++itr)
    {
        cout << itr->second << endl;
        // itr->second = 10;  // error
    }

    // advance
    unordered_map<string, string>::iterator itrm = myMap.begin();
    advance(itrm, 3);                           // itrm指向：h:10
    int nDistance = distance(itr, vec.begin()); // distance only support for random access iterator。 nDistance = -1

    // ===
    // 1 insert iterator
    vector<int> vec1 = {4, 5};
    vector<int> vec2 = {12, 14, 16, 18};
    vector<int>::iterator itv = vec2.begin();
    insert_iterator<vector<int>> i_itrv(vec2, itv);
    copy(vec1.begin(), vec1.end(), i_itrv);
    for (vector<int>::iterator itv1 = vec2.begin(); itv1 != vec2.end(); ++itv1)
    {
        cout << *itv1 << endl;
    }
    // 2 stream iterator
    // vector<string> vec4;
    // copy(istream_iterator<string>(cin), istream_iterator < string(), back_inserter(vec4));
    // reverse iterator
    vector<int> v3 = {1,2,3,4,5,6};
    for(vector<int>::reverse_iterator ritr3 = v3.rbegin(); ritr3 != v3.rend(); ++ritr3){
        cout << *ritr3 << endl;
    }
}