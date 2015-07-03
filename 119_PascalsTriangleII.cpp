// 119 Pascal's Triangle II
// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex < 0) return res;
        res.push_back(1);
        if(rowIndex == 0) return res;
        for(int i = 1; i < rowIndex; ++i) {
            long long val = (long long)res[i-1]*(rowIndex-i+1)/i;
            res.push_back((int)val);
        }
        res.push_back(1);
        return res;
    }
};