#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TrieNode {

    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }

            isTerminal = false;
        }
};

class Trie {

    public:
        TrieNode *root;

        Trie() {
            root = new TrieNode('\0'); // creating root node with '\0' character (null character)
        }

        void insertUtil(TrieNode *root , string word) {
            //base case
            if(word.length() == 0) {
                root -> isTerminal = true;
                return;
            }   

            int index = word[0] - 'a'; // assuming the word contains only lowercase letters
            TrieNode *child;

            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }

            else{
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            insertUtil(child , word.substr(1)); // recursive call
        }

        void insert(string word) {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode *root , string word) {
            
            // base case
            if(word.length() == 0) {
                return root -> isTerminal;
            }

            int index = word[0] - 'a'; // assuming the word contains only lowercase letters
            TrieNode *child;

            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }

            else{
                return false; // character not present
            }

            // recursive call
            searchUtil(child , word.substr(1));
        }

        bool search(string word) {
            searchUtil(root, word);
        }
};

int main() {

    Trie *t = new Trie();
    t -> insert("abc");
    t -> insert("ab");

    if(t -> search("abc")) {
        cout << "Present" << endl;
    }

    else {
        cout << "Not Present" << endl;
    }

 return 0;
}