#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
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

    void insertUtil(TrieNode *root, string word) {

        // base case
        if(word.length() == 0) {
            root -> isTerminal = true;
            return;
        }

        // assumption, word will be in lowercase
        int index = word[0] - 'a';
        TrieNode *child;

        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }

        else {
            TrieNode *newNode = new TrieNode(word[0]);
            root -> children[index] = newNode;
            child = newNode;
        }

        // recursive call
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root , string word) {

        // base case
        if(word.length() == 0) {
            return root -> isTerminal;
        }

        // assumption, word will be in lowercase
        int index = word[0] - 'a';
        TrieNode *child;

        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }

        else {
            return false;
        }

        // recursive call
        return searchUtil(child, word.substr(1));
    }

    bool search(string word){
        return searchUtil(root , word);
    }


};

int main() {

    Trie *t = new Trie();

    t -> insertWord("asdf");

    cout << "Trie Search Results : " << t -> search("asdf") << endl;




 return 0;
}