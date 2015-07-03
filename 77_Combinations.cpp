// 77 Combinations
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

class Solution {
public:
    void dfs(int st, int n, int k, vector<int> vec, vector<vector<int> >& res) {
        if(vec.size() == k) {
            res.push_back(vec);
            return;
        }
        for(int i = st; i <= n; ++i) {
            vec.push_back(i);
            dfs(i+1, n, k, vec, res);
            vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        if(k == 0 || n < k) return res;
        vector<int> vec;
        dfs(1, n, k, vec, res);
        return res;
    }

    vector<vector<int> > combine2(int n, int k) {
        vector<vector<int>>  res;
        if(k == 0 || n < k)
        {
            return res;
        }
        if(k == 1)
        {
            for(int i = 1; i <= n; ++i)
            {
                res.push_back(vector<int>(1,i));
            }
            return res;
        }
        for(int i = n; i >= k; --i)
        {
            vector<vector<int>> temp_res = combine(i-1, k-1);
            for(int j = 0; j < temp_res.size(); ++j)
            {
                temp_res[j].push_back(i);
                res.push_back(temp_res[j]);
            }
        }
        return res;
    }

    vector<vector<int> > combine2(int n, int k) {
        vector<vector<int> > res;
        if(k == 0 || n < k) return res;
        int st = 1;
        vector<int> vec;
        while(st<=n-k+1) {
            int cur_st = st;
            if(vec.empty() == false) cur_st = vec.back()+1;
            for(int i = cur_st; i <= n; ++i) {
                vec.push_back
            }
        }
    }
};