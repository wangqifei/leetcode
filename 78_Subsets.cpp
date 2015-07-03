// 78 Subsets
// Given a set of distinct integers, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
#include <vector>
#include <iostream>
using namespace::std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> vec;
        res.push_back(vec);
        if(nums.empty()) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            int tempSize = res.size();
            for(int j = 0; j < tempSize; ++j) {
                vector<int> temp_vec = res[j];
                temp_vec.push_back(nums[i]);
                res.push_back(temp_vec);
            }
        }
        return res;
    }

    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) {
            res.push_back(nums);
            return res;
        }
        sort(nums.begin(), nums.end());
        int val = nums.back();
        nums.pop_back();
        vector<vector<int> > temp_res = subsets(nums);
        int tempSize = temp_res.size();
        for(int j = 0; j < tempSize; ++j) {
            vector<int> temp_vec = temp_res[j];
            res.push_back(temp_vec);
            temp_vec.push_back(val);
            res.push_back(temp_vec);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int A[] = {1,2,3};
    int n = 3;
    vector<int> nums(A, A+n);
    Solution mySolution;
    vector<vector<int> > res = mySolution.subsets(nums);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}