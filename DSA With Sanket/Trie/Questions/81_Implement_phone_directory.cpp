/* 
? lecture 81 : Implement phone directions
? https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM


Problem statement
You are given a list/array of strings which denotes the contacts that exist in your phone directory. The search query on a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’. One special property of the search function is that when a user searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character.

Note :
If no suggestions are found, return an empty 2D array.
For Example :

In the above example everytime we enter a character, a few suggestions display the strings which contain the entered string as prefixes.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 50
1 <= N <= 100
1 <= len <= 10
ARR[i] contains lowercase English alphabets.

All the given strings contain lowercase English alphabets.

Time Limit: 1 sec.
Sample Input 1 :
2
5
cod coding codding code coly
coding
2
ninjas coding
ninja
Sample Output 1 :
cod coding codding code coly
cod coding codding code coly
cod coding codding code coly
coding
coding
coding
ninjas
ninjas
ninjas
ninjas
ninjas
Explanation to Sample Input 1 :
In the first test case, 
The suggestions for “c” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestions for “co” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestions for “cod” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestion for “codi” is {“coding”}.
The suggestion for “codin” is {“coding”}.
The suggestion for “coding” is {“coding”}.

In the second test case, 
The suggestion for “n” is {“ninjas”}.
The suggestion for “ni” is {“ninjas”}.
The suggestion for “nin” is {“ninjas”}.
The suggestion for “ninj” is {“ninjas”}.
The suggestion for “ninja” is {“ninjas”}.
Sample Input 2 :
3
2
coding ninjas
cell
2
ab abc
a
2
ab abc
b
Sample Output 2 :
coding
ab abc
No suggestions found
Explanation to Sample Input 2 :
In the first test case, 
The suggestion for “c” is {“coding”}.
For the rest of the letters, there are no suggestions.

In the second test case,
The suggestion for “a” is {“ab”, “abc”}.

In the third test case, no suggestions are found.
 */

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
    string queryStr = "cod";
    vector<vector<string>> result = phoneDirectory(contactList, queryStr);

    for (const auto &suggestions : result) {
        for (const auto &word : suggestions) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}