// 212 Word Search II Total Accepted: 2971 Total Submissions: 19713 My Submissions Question Solution 
// Given a 2D board and a list of words from the dictionary, find all words in the board.

// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

// For example,
// Given words = ["oath","pea","eat","rain"] and board =

// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// Return ["eat","oath"].
// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

// click to show hint.

// You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

// If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.

// Hide Tags Backtracking Trie

#include <vector>
#include <string>
using namespace::std;
class TrieNode {
public:
    bool isend;
    int idx;
    TrieNode* children[26];
    TrieNode():isend(false),idx(-1) {
        fill_n(this->children, 26, nullptr);
    }
};
class Solution {
public:
    void insertWord(TrieNode* root, string word, int idx) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); ++i) {
            if(node->children[word[i]-'a'] == nullptr) {
                node->children[word[i]-'a'] = new TrieNode();
            }
            node = node->children[word[i]-'a'];
        }
        node->isend = true;
        node->idx = idx;
    }
    
    TrieNode* buildTrie(vector<string> words) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); ++i) {
            insertWord(root, words[i], i);
        }
        return root;
    }
    
    void check(vector<vector<char> >& board, int i, int j, int h, int w, TrieNode* root, vector<string>& words, vector<string>& res) {
        if(board[i][j] == 'X') return;
        char temp = board[i][j];
        if(root->children[temp-'a'] == nullptr) return;
        if(root->children[temp-'a']->isend) {
            res.push_back(words[root->children[temp-'a']->idx]);
            root->children[temp-'a']->isend = false;  //Caution!!!, set to false to indicate this word has been found
        }
        board[i][j] = 'X';
        if(i > 0)   check(board, i-1, j, h, w, root->children[temp-'a'], words, res);
        if(i < h-1) check(board, i+1, j, h, w, root->children[temp-'a'], words, res);
        if(j > 0)   check(board, i, j-1, h, w, root->children[temp-'a'], words, res);
        if(j < w-1) check(board, i, j+1, h, w, root->children[temp-'a'], words, res);
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int h = board.size();
        if(h == 0) return res;
        int w = board[0].size();
        if(words.empty()) return res;
        TrieNode* root = buildTrie(words);
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                check(board, i, j, h, w, root, words, res);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}