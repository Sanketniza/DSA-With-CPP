
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
 
int main() { 

    // * different between map and unordered_map
    // * map is sorted
    // * unordered_map is not sorted
    // * map is slow
    // * unordered_map is fast

    /* 
                             | map                | unordered_map
            ---------------------------------------------------------
            Ordering        | increasing order    | no ordering
                            | of keys(by default) |

            Implementation  | Self balancing BST  | Hash Table
                            | like Red-Black Tree |  

            search time     | log(n)              | O(1) -> Average 
                            |                     | O(n) -> Worst Case

            Insertion time  | log(n) + Rebalance  | Same as search

            Deletion time   | log(n) + Rebalance  | Same as search
    
     */

        // todo: map implementation or creation

        // map<int, int> m;

        // todo: ordered_map implementation or creation    

        unordered_map<string, int> m;

        // todo: insertion in both map and unordered_map

        //^ 1 method of insertion

            pair<string, int> p = make_pair("sanket", 1);
            m.insert(p);

        //^ 2 method of insertion

            pair<string, int> p1("sanket1", 2);
            m.insert(p1);

        //^ 3 method of insertion

            m["sanket2"] = 3;

        // todo: searching in both map and unordered_map

        cout << m.size() << endl;

        cout << m["sanket1"] << endl;

        cout << m.at("sanket2") << endl;

        //
         for (auto i = m.begin();  i != m.end(); i++){
                 cout << i->first 
                  << " : "
                  << i->second << '\n';
            }

        // 

      /*   map<string,int> :: iterator it = m.begin();

        while(it != m.end()) {
            cout << it->first << " : " << it->second << endl;
            it++;
        } */



        //^ 1 method of searching

            string key = "sanket2";
            if(m.find(key) != m.end()) {
                cout << "Key " << key << " is present" << endl;
            }
            else {
                cout << "Key " << key << " is not present" << endl;
            }

        //^ 2 method of searching

            if(m.count(key)) {
                cout << "Key " << key << " is present" << endl;
            }



    return 0;
}