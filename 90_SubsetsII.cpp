// 90 Subsets II
// Given a collection of integers that might contain duplicates, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,2], a solution is:

// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        res.push_back(vec);
        if(nums.empty()) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int prev = nums[0]-1;
        for(int i = 0; i < nums.size(); ++i) {
            int sz = res.size();
            int begin = 0;
            if(nums[i] == prev) {
                begin = sz - cnt;
            }
            cnt = 0;
            for(int j = begin; j < sz; ++j) {
                vec = res[j];
                vec.push_back(nums[i]);
                res.push_back(vec);
                cnt++;
            }
            prev = nums[i];
        }
        return res;
    }
};