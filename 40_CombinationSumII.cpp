// 40 Combination Sum II
// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
// A solution set is: 
// [1, 7] 
// [1, 2, 5] 
// [2, 6] 
// [1, 1, 6] 

class Solution {
public:
    void dfs(vector<int>& candidates, int target, int st, vector<int> vec, vector<vector<int> >& res)
    {
        if(target == 0)
        {
            res.push_back(vec);
            return;
        }
        for(int i = st; i < candidates.size(); ++i)
        {
            if(i > st && candidates[i] == candidates[i-1]) continue;
            if(target >= candidates[i])
            {
                vec.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], i+1, vec, res);
                vec.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> vec;
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, vec, res);
        return res;
    }
};