#include<iostream>
using namespace std;


// Assuming the TrieNode class is defined as follows:
class TrieNode {
public:

    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {

        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {

        // Base case: if the word is empty, mark the current node as terminal
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assuming the word contains only lowercase letters
        int index = word[0] - 'a'; // this is the index of the first character of the word that is in lowercase and that here we are insuring
        TrieNode* child;

        // If the first character of the word is present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } 

        else {
            // Create a new TrieNode and add it to the children array
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursively insert the remaining word
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word) {

        // base case
        if(word.length() == 0) {
            return root -> isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }

        else {
            return false;
        }

        // recursive call
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);

    }

    


 
};

int main() { 

    Trie *t = new Trie();

    t->insertWord("asdf");  // Using lowercase to match implementation

    cout << "Trie Search Results : " << t->search("asdf") << endl;

    return 0;

}
