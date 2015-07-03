// 211 Add and Search Word - Data structure design Total Accepted: 4466 Total Submissions: 21578 My Submissions Question Solution 
// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

// For example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
// Note:
// You may assume that all words are consist of lowercase letters a-z.

// click to show hint.

// You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
// Hide Tags Backtracking Data Structure Trie


class TrieNode {
public:
    char ch;
    bool isend;
    vector<TrieNode*> children;
    TrieNode():ch(' '), isend(false) {}
    TrieNode(char c):ch(c), isend(false) {}
    
    TrieNode* subNode(char c) {
        for(auto child:children) {
            if(child->ch == c) return child;
        }
        return nullptr;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        if(search(word)) return;
        TrieNode* node = root;
        for(int i = 0; i < word.size(); ++i) {
            if(node->subNode(word[i]) != nullptr) {
                node = node->subNode(word[i]);
            }
            else {
                TrieNode* newNode = new TrieNode(word[i]);
                node->children.push_back(newNode);
                node = newNode;
            }
        }
        node->isend = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.empty()) return false;
        return searchSubNode(word, 0, root);
    }
    
    bool searchSubNode(string& word, int i, TrieNode* root) {
        if(i == word.size()) 
            return root->isend;
        if(word[i] == '.') {
            for(auto child:root->children) {
                if(searchSubNode(word, i+1, child))
                    return true;
            }
            return false;
        }
        if(root->subNode(word[i]) == nullptr) return false;
        return searchSubNode(word, i+1, root->subNode(word[i]));
    }
private:
    TrieNode* root;
};


class TrieNode {
public:
    bool isend;
    TrieNode* children[26];
    TrieNode():isend(false){
        for(int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        if(search(word)) return;
        TrieNode* node = root;
        for(auto ch:word) {
            if(node->children[ch-'a'] == NULL) {
                node->children[ch-'a'] = new TrieNode(); 
            }
            node = node->children[ch-'a'];
        }
        node->isend = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.empty()) return false;
        return searchSubNode(word, 0, root);
    }

    bool searchSubNode(string word, int i, TrieNode* node) {
        if(i == word.size()) return node->isend;
        if(word[i] == '.') {
            for(auto child:node->children){
                if(child != NULL && searchSubNode(word, i+1, child))
                    return true;
            }
            return false;
        }
        else {
            if(node->children[word[i]-'a'])
                return searchSubNode(word, i+1, node->children[word[i]-'a']);
            else return false;
        }
    }
private:
    TrieNode* root;
};


// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");