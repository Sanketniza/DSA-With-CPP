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


    return 0;
}