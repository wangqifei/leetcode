// 228 Summary Ranges Total Accepted: 130 Total Submissions: 696 My Submissions Question Solution 
// Given a sorted integer array without duplicates, return the summary of its ranges.

// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

// Hide Tags Array


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        if(nums.size() == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        vector<vector<int> > range;
        int st = 0;
        int ed = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]+1) {
                ed++;
            }
            else {
                range.push_back(vector<int>({st, ed}));
                st = i;
                ed = i;
            }
        }
        range.push_back(vector<int>({st, ed}));
        for(int i = 0; i < range.size(); ++i) {
            if(range[i][0] == range[i][1]) {
                res.push_back(to_string(nums[range[i][0]]));
            }
            else {
                string str = to_string(nums[range[i][0]])+"->"+to_string(nums[range[i][1]]);
                res.push_back(str);
            }
        }
        return res;
    }
};