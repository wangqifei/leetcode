// 126 Word Ladder II
// Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,

// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// Return
//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]
// Note:
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// Hide Tags Array Backtracking Breadth-first Search String


class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > res;
        queue<pair<string, vector<string> > > q;
        q.push(make_pair(start, vector<string>({start})));
        if(dict.find(start) != dict.end()) dict.erase(start);
        int minLen = INT_MAX;
        while(q.empty() == false) {
            string currWord = q.front().first;
            vector<string> path = q.front().second;
            q.pop();
            for(int i = 0; i < currWord.size(); ++i)
            {
                string nextWord = currWord;
                for(int j = 'a'; j <= 'z'; ++j) {
                    nextWord[i] = j;
                    if(nextWord == end) {
                        if(minLen >= path.size()+1) {
                            path.push_back(end);
                            res.push_back(path);
                            minLen = path.size();
                            path.pop_back();
                            break;
                        }
                    }
                    if(dict.find(nextWord) != dict.end()) {
                        path.push_back(nextWord);
                        q.push(make_pair(nextWord, path));
                        dict.erase(nextWord);
                        path.pop_back();
                    }
                }
            }
        }
        return res;
    }
};