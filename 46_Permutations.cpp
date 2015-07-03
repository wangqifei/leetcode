// Permutations
// Given a collection of numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;
        if(nums.size() == 1) res.push_back(nums);
        for(int i = 0; i < nums.size(); ++i)
        {
            int val = nums[i];
            swap(nums[i], nums.back());
            nums.pop_back();
            vector<vector<int> > temp_res = permute(nums);
            for(int j = 0; j < temp_res.size(); ++j)
            {
                temp_res[j].push_back(val);
                res.push_back(temp_res[j]);
            }
            nums.push_back(val);
            swap(nums[i], nums.back());
        }
        return res;
    }

    vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;
        if(nums.size() == 1) res.push_back(nums);
        int val = nums.back();
        nums.pop_back();
        vector<vector<int> > temp_res = permute2(nums);
        for(int i = 0; i < temp_res.size(); ++i)
        {
            for(int j = 0; j <= temp_res[i].size(); ++j)
            {
                vector<int> vec(temp_res[i]);
                vec.insert(vec.begin()+j, val);
                res.push_back(vec);
            }
        }
        return res;
    }

    vector<vector<int>> permute3(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;
        dfs(nums, 0, nums.size()-1, res);
        return res;
    }

    void dfs(vector<int>& nums, int st, int ed, vector<vector<int> >& res)
    {
        if(st == ed)
        {
            res.push_back(nums);
            return;
        }
        for(int i = st; i <= ed; ++i)
        {
            swap(nums[st], nums[i]);
            dfs(nums, st+1, ed, res);
            swap(nums[i], nums[ed]);
        }
    }
};