#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TrieNode{

    public:
        char data;
        TrieNode *children[26];
        int ChildrenCount;
        bool isTerminal;

        TrieNode(char data) {

            this -> data = data;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }

            ChildrenCount = 0;
            isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode *root;

        Trie(char ch ) {
            root = new TrieNode(ch);
        }

        void sertchUtil(TrieNode *root, string word ) {

            // base case
            if(word.length() == 0) {
                root -> isTerminal = true;
                return;
            }

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
            sertchUtil(child, word.substr(1));
        }

        void search(string word) {
            sertchUtil(root, word);
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

    vector<string> v = {"apple", "app", "apricot", "banana", "bat"};
    int n = v.size();

    Trie *t = new Trie('\0');
    

    for(int i = 0; i < n; i++) {
        t -> search(v[i]);
    }

    string frist = v[0];
    string ans = "";

    t -> lcp(frist, ans);

    cout << "ans is : " << ans << endl;

 return 0;
}