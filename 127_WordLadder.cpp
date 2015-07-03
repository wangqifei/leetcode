// 127 Word Ladder
// Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,

// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord,1));
        while(q.empty() == false)
        {
            string cur = q.front().first;
            int step = q.front().second;
            q.pop();
            for(int i = 0; i < cur.length(); i++)
            {
                string cur_new = cur;
                for(int j = 'a'; j <= 'z'; j++) //comparing the current word with the word in wordDict costs more time than construct the next word
                {
                    cur_new[i] = j;
                    if(cur_new == endWord)
                    {
                        return ++step;
                    }
                    if(wordDict.find(cur_new) != wordDict.end())
                    {
                        q.push(make_pair(cur_new, step+1));
                        wordDict.erase(cur_new);
                    }
                }
            }
        }
        return 0;
    }
};