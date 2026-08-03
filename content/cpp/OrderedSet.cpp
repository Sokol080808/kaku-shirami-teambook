/**
 * Author: Igor Markelov
 * Date: 2022-11-05
 * Source:
 * https://github.com/zemen/Jinotega-notebook/blob/master/algo/structures/ordered_set.cpp
 * Description: A set (not multiset!) with support for finding the n'th
 * element, and finding the index of an element.
 * To get a map, change \texttt{null\_type}.
 * Time: O(\log(n))
 */

#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ordered_set<int> X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);
    
    assert(*X.find_by_order(1) == 2);
    assert(*X.find_by_order(2) == 4);
    assert(*X.find_by_order(4) == 16);
    assert(X.find_by_order(6) ==X.end());

    assert(X.order_of_key(-5) == 0);
    assert(X.order_of_key(1) == 0);
    assert(X.order_of_key(3) == 2);
    assert(X.order_of_key(4) == 2);
    assert(X.order_of_key(400) == 5);
    // std::cout << *X.find_by_order(1) << std::endl;            // 2
    // std::cout << *X.find_by_order(2) << std::endl;            // 4
    // std::cout << *X.find_by_order(4) << std::endl;            // 16
    // std::cout << (end(X) == X.find_by_order(6)) << std::endl; // true

    // std::cout << X.order_of_key(-5) << std::endl;  // 0
    // std::cout << X.order_of_key(1) << std::endl;   // 0
    // std::cout << X.order_of_key(3) << std::endl;   // 2
    // std::cout << X.order_of_key(4) << std::endl;   // 2
    // std::cout << X.order_of_key(400) << std::endl; // 5
    return 0;
}
