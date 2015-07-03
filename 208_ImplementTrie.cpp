// 208 Implement Trie (Prefix Tree) Total Accepted: 6678 Total Submissions: 26892 My Submissions Question Solution 
// Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

// Hide Tags Data Structure Trie


class TrieNode {
public:
    // Initialize your data structure here.
    char ch;
    bool isend;
    int numChildren;
    vector<TrieNode*> children;
    TrieNode():ch(' '),isend(false),numChildren(0) {}
    TrieNode(char c):ch(c),isend(false),numChildren(0) {}
    TrieNode* subNode(char c) {
        if(children.empty() == false) {
            for(auto child:children) {
                if(child->ch == c) return child;
            }
        }
        return nullptr;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(search(word)) return;
        TrieNode* curr = root;
        for(auto c:word) {
            TrieNode* node = curr->subNode(c);
            if(node != nullptr) {
                curr = node;
            }
            else {
                curr->children.push_back(new TrieNode(c));
                curr->numChildren++;
                curr = curr->subNode(c);
            }
        }
        curr->isend = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for(auto c:word) {
            node = node->subNode(c);
            if(node == nullptr) return false;
        }
        return node->isend;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto c:prefix) {
            node = node->subNode(c);
            if(node == nullptr) return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");