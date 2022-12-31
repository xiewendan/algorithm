#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <iterator>

#include <algorithm>

#include <numeric>
#include <functional>
using namespace std;


int main()
{
    /*
    1 non modifying algorithms
        count
            count, count_if
        min and max
            max_element, min_element, minmax_element
        linear search
            find, find_if, find_if_not, search_n, search, find_end, find_first_of, adjacent_find
        compare
            equal, is_permutation, mismatch, lexicographical_compare
        attribute
            is_sorted, is_sorted_until, is_partitioned, is_heap, is_heap_until, all_of, any_of, none_of

    2 value-changing algorithm - change the element values
        copy
            copy, copy_if, copy_n, copy_backward
        move
            move, move_backward
        transform
            transform
        swap
            swap_ranges
        fill
            fill, fill_n, generate, generate_n
        replace
            replace, replace_if, replace_copy, replace_copy_if
        remove
            remove, remove_copy, remove_copy_if, unique, unique_copy
      order-changing algorithm
        reverse
            reverse, reverse_copy
        rotate
            rotate, rotate_copy
        permute(排列)
            next_permutation, prev_permutation
        shuffle
            random_shuffle

    3 sorting algorithm requires random access iterators - vector, deque, container array, native array
        sort
            sort, partial_sort, nth_element, partition, stable_partition,
        heap
            make_heap, pop_heap, push_heap, sort_heap

    4 algorithms that require data being pre-sorted
        Binary search
			binary_search, includes, lower_bound, upper_bound, equal_range
        merge
			merge, inplace_merge
        set operations
			set_union, set_intersection, set_difference, set_sysmetric_difference
        numeric function
            accumulate, inner_produce, partial_sum, adjacent_difference
    */

 //   vector<int> vec = { 9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7 };
 //   vector<int> vec2 = { 9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7 };
 //   vector<int> vec3 = { 60, 9, 90, 8, 45, 87, 90, 69, 69, 55, 7 };
 //   vector<int> vec4 = { 9, 60, 90, 8, 87, 45, 90, 69, 69, 55, 7 };

 //   // 1.1 counting
 //   int n = count(vec.begin() + 2, vec.end() - 1, 69); // 2
 //   int m = count_if(vec.begin(), vec.end(), [](int x)
 //       { return x < 10; }); // 3

 //   // 1.2 min and max
 //   vector<int>::iterator itr = max_element(vec.begin() + 2, vec.end()); // 90
 //   itr = max_element(vec.begin(), vec.end(), [](int x, int y) {return x%10 < y %10; }); // 9
 //   itr = min_element(vec.begin(), vec.end());

 //   // 1.3 linear search
 //   itr = find(vec.begin(), vec.end(), 55); // 55
 //   itr = find_if(vec.begin(), vec.end(), [](int x) {return x > 80; }); // 90
 //   itr = find_if_not(vec.begin(), vec.end(), [](int x) {return x > 80; }); // 9
 //   itr = search_n(vec.begin(), vec.end(), 2, 69); // 69
 //   
 //   vector<int> sub = { 45, 87, 90, 69};
 //   itr = search( vec.begin(), vec.end(), sub.begin(), sub.end() ); // 45
 //   itr = find_end(vec.begin(), vec.end(), sub.begin(), sub.end()); // 45
 //   
 //   vector<int> items = { 87, 69, 2};
 //   itr = find_first_of(vec.begin(), vec.end(), items.begin(), items.end());    // 87
 //   itr = find_first_of(vec.begin(), vec.end(), items.begin(), items.end(), 
 //       [](int x, int y) {return x == y * 4; });    // 8

 //   itr = adjacent_find(vec.begin(), vec.end()); // 69
 //   itr = adjacent_find(vec.begin(), vec.end(), [](int x, int y) {return x == y + 82; }); // 90

 //   // 1.4 compare
 //   bool bRet = equal(vec.begin(), vec.end(), vec2.begin());    // true
 //   bRet = is_permutation(vec.begin(), vec.end(), vec2.begin()); // true
 //   pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr = mismatch(vec.begin(), vec.end(), vec4.begin());  // (45, 87)
 //   bRet = lexicographical_compare(vec.begin(), vec.end(), vec4.begin(), vec4.end());   // 是否小于：true
 //   
 //   // 1.5 check attribute
 //   bRet = is_sorted(vec.begin(), vec.end()); // false
 //   itr = is_sorted_until(vec.begin(), vec.end()); // 8

 //   bRet = is_partitioned(vec.begin(), vec.end(), [](int x) {return x > 80; }); // false
 //   bRet = is_heap(vec.begin(), vec.end()); // false
 //   itr = is_heap_until(vec.begin(), vec.end()); // 60  // 大顶堆

 //   bRet = all_of(vec.begin(), vec.end(), [](int x) {return x > 80; }); // false
 //   bRet = any_of(vec.begin(), vec.end(), [](int x) {return x > 80; }); // true
 //   bRet = none_of(vec.begin(), vec.end(), [](int x) {return x > 80; }); // false

 //   // 2.1 copy
 //   vec = { 9, 60, 70, 8, 45, 87, 90 };
 //   vec2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
 //   copy(vec.begin(), vec.end(), vec2.begin()); // vec2： 9, 60, 70, 8, 45, 87, 90, 0, 0, 0, 0

 //   vec2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
 //   copy_if(vec.begin(), vec.end(), vec2.begin(), [](int x) {return x > 80; }); // vec2：87, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0

 //   vec2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
 //   copy_n(vec.begin(), 4, vec2.begin()); // vec2：9, 60, 70, 8, 0, 0, 0, 0, 0, 0, 0

 //   vec2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
 //   copy_backward(vec.begin(), vec.end(), vec2.end());  // vec2：0, 0, 0, 0, 9, 60, 70, 8, 45, 87, 90

 //   // 2.2 move
 //   vector<string> s_vec = { "apple", "orange", "pear", "grape" };// 4 items
 //   vector<string> s_vec2 = { "", "", "", "", "", "" }; // 6 items
 //   move(s_vec.begin(), s_vec.end(), s_vec2.begin()); // s_vec: {"", "", "", ""}, s_vec2 = {"apple", "orange", "pear", "grape", "", ""}
 //   
 //   s_vec = { "apple", "orange", "pear", "grape" };// 4 items
 //   s_vec2 = { "", "", "", "", "", "" }; // 6 items
 //   move_backward(s_vec.begin(), s_vec.end(), s_vec2.end()); // s_vec: {"", "", "", ""}, s_vec2 = {"", "", "apple", "orange", "pear", "grape"}

 //   // 2.3 transform
 //   vec = { 9, 60, 70, 8, 45, 87, 90 };
 //   vec2 = { 9, 60, 70, 8, 45, 87, 90 };
 //   vec3 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
 //   transform(vec.begin(), vec.end(), vec3.begin(), [](int x) {return x - 1; });
 //   transform(vec.begin(), vec.end(), vec2.begin(), vec3.begin(), [](int x, int y) {return x + y; });

 //   // 2.4 swap
 //   vector<int> veci = { 9, 60, 70, 8, 45, 87, 90 };
 //   vector<int> veci2 = { 9, 60, 70, 8, 45, 87, 90 };
 //   // swap_ranges(veci.begin(), veci.end(), veci2.begin());

 //   // 2.5 fill
 //   vec = { 0, 0, 0, 0, 0 };
 //   fill(vec.begin(), vec.end(), 9);    // vec: {9, 9, 9, 9, 9)

 //   vec = { 0, 0, 0, 0, 0 };
 //   fill_n(vec.begin(), 3, 9);    // vec: {9, 9, 9, 0, 0)

 //   vec = { 0, 0, 0, 0, 0 };
 //   generate(vec.begin(), vec.end(), rand);

 //   vec = { 0, 0, 0, 0, 0 };
 //   // generate_n(vec.begin(), 3, rand);
	//for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	//{
	//	cout << *it << endl;
	//}


 //   // 2.6 replace
 //   replace(vec.begin(), vec.end(), 6, 9);
 //   replace_if(vec.begin(), vec.end(), [](int x) {return x > 80; }, 9);
 //   replace_copy(vec.begin(), vec.end(), vec2.begin(), 6, 9);

 //   // 2.7 remove
 //   remove(vec.begin(), vec.end(), 3);
 //   remove_if(vec.begin(), vec.end(), [](int x) {return x > 80; });
 //   remove_copy(vec.begin(), vec.end(), vec2.begin(), 6);

 //   unique(vec.begin(), vec.end());
 //   unique(vec.begin(), vec.end(), less<int>());

}
