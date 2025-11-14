#include<bits/stdc++.h>
using namespace std;
class TrieNode {
    public: 
    vector<TrieNode*> children;
    bool flg = false;
    TrieNode () {
        children.resize(26, NULL);
    }
};

class Trie {
    TrieNode * root;
    public: 
    Trie () {
        root = new TrieNode;
    }
    void insert (string word) {
        TrieNode * node = root;
        for (auto x : word) {
            if (node->children[x-'a']) {
                node = node->children[x-'a'];
            } else {
                node->children[x-'a'] = new TrieNode();
                node = node->children[x-'a'];
            }
        }
        node->flg = true;
    }
    bool ispresent (string word) {
        TrieNode * node = root;
        for(auto x: word) {
            if (!node->children[x-'a']) {
                return false;
            } else {
                node = node->children[x-'a'];
            }
        }
        return node->flg;
    }
};

int main() {
   Trie t ;
   t.insert("bharat");
   t.insert("not");
   t.insert("xor");
   t.insert("blue");
   t.insert("nand");
   cout<<t.ispresent("bharat") ? "pagal": "nothing";
    return 0;
}