// Permutations II 
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;
        dfs(nums, 0, res);
        return res;
    }
    void dfs(vector<int>& nums, int st, vector<vector<int> >& res)
    {
        if(st == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = st; i < nums.size(); ++i)
        {
            if(check(nums, st, i))
            {
                swap(nums[st], nums[i]);
                dfs(nums, st+1, res);
                swap(nums[st], nums[i]);
            }
        }
    }
    bool check(vector<int>& nums, int st, int ed)
    {
        for(int i = st; i < ed; ++i)
        {
            if(nums[i] == nums[ed]) return false;
        }
        return true;
    }
};