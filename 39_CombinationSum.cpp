// 39 Combination Sum
// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

class Solution {
public:
    void dfs(vector<int>& candidates, int st, int sum, int target, vector<int> vec, vector<vector<int> >& res)
    {
        if(sum == target)
        {
            res.push_back(vec);
            return;
        }
        for(int i = st; i < candidates.size(); ++i) //Caution it is not necessary to add one more loop here. The st is usually start from i
        {
            if(sum+candidates[i]<=target)
            {
                vec.push_back(candidates[i]);
                dfs(candidates, i, sum+candidates[i], target, vec, res);
                vec.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target, vec, res);
        return res;
    }
};