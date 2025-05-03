#include<iostream>
#include<string>
#include<vector>

using namespace std;
 
class TrieNode{

    public:

        char data;
        TrieNode *children[26];
        int ChildrenCount;
        bool isTerminal;

        TrieNode(char data) {

            this->data = data;

            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }

            ChildrenCount = 0;
            isTerminal = false;

        }
}; 

 class Trie{

    public:

        TrieNode *root;

        Trie(char ch) {

            root = new TrieNode(ch);
        }

        void insertUtil (TrieNode *root, string word) {
            
            // base case

            if(word.length() == 0){
                root -> isTerminal = true;
                return;
            }

            // assume word in lowercase

            int index = word[0] - 'a';

            TrieNode *child;

            // is word present
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }

            else {
                child = new TrieNode(word[0]);
                root -> ChildrenCount++;
                root -> children[index] = child;
            }

            // recursive call
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }

        void lcp(string word, string &ans) {

            for(int i = 0; i < word.length(); i++) {
                char ch = word[i];


                if(root -> ChildrenCount == 1) {
                    ans.push_back(ch);

                    int index = ch - 'a';
                    root = root -> children[index];
                }

                else {
                    break;
                }

                if(root -> isTerminal) {
                    break;
                }
            }
        }    
};

string longestCommonPrefix(vector<string>& arr , string &ans , int n) {

    // traversing the all characters of the first string
    for(int i = 0; i < arr[0].length(); i++ ) { 

        // get first character of the first string
        char ch = arr[0][i];
        bool match = true;

        // check if this character is present in all the strings in array
        for(int j = 1; j < n; j++) {

            // if the character is not present in the string
            if(arr[j][i] != ch) {
                match = false;
                break;
            }
        }

        // if the character is not present in all the strings
        if(match == false) {
            break;
        }

        // if the character is present in all the strings
        ans.push_back(ch);
    }
    return ans;
}

int main() { 

     vector<string> arr1 = {"coding", "codezen", "codingninja", "coder"};
     int n = arr1.size();

    Trie *t = new Trie('\0');

    // insert all the string into the trie

    for(int i = 0; i < n; i++) {
        // cout << arr1[i] << endl;
        t->insertWord(arr1[i]);
    }

    string first = arr1[0];
    // cout << first << endl;

    string ans = "";

    t -> lcp (first , ans);

    cout << ans << endl;

// todo: second approach with time complexity O(n * m) and space complexity O(1)
    string ans2 = "";
    string done = longestCommonPrefix(arr1 , ans2 , n);
    cout << "done is : " << done << endl;

    return 0;
}