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
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode *root , string word) {
            
            // base case
            if(word.length() == 0) {
                root -> isTerminal = true;
                return;
            }

            // assuming the word contains only lowercase letters
            int index = word[0] - 'a';

            TrieNode *child;

            // if character is present
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }

            // if character is not present
            else {
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            // recursive call
            insertUtil(child , word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root , word);
        }
};

int main() {

    Trie *t = new Trie();
    t -> insertWord("hello");
    t -> insertWord("hell");
    t -> insertWord("he");
    t -> insertWord("hi");
    t -> insertWord("hii");

    // trie is ready


 return 0;
}