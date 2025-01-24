#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode *children[26];
    int childrenCount;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childrenCount = 0;
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    void insert(string word) {
        insertWord(root, word);
    }

    void print(TrieNode *curr, vector<string> &temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode *next = curr->children[ch - 'a'];
            if (next != NULL) {
                prefix.push_back(ch);
                print(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str) {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];
            prefix.push_back(lastch);

            TrieNode *curr = prev->children[lastch - 'a'];
            if (curr == NULL) {
                break;
            }

            vector<string> temp;
            print(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }

        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr) {
    Trie *t = new Trie();
    for (int i = 0; i < contactList.size(); i++) {
        string ch = contactList[i];
        t->insert(ch);
    }
    return t->getSuggestion(queryStr);
}

int main() {
    
    vector<string> contactList = {"cod", "coding", "codding", "code", "coly"};
    string queryStr = "coding";
    vector<vector<string>> result = phoneDirectory(contactList, queryStr);

    for (const auto &suggestions : result) {
        for (const auto &word : suggestions) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}