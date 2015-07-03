// 18 4Sum
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
//     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>> > mp;
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            for(int j = i+1; j < len; ++j)
            {
                mp[nums[i]+nums[j]].push_back(make_pair(i,j));
            }
        }
        
        for(int i = 0; i < len; ++i)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < len; ++j)
            {
                if(j > (i+1) && nums[j] == nums[j-1]) continue;
                int sum = target-nums[i]-nums[j];
                if(mp.find(sum) != mp.end())
                {
                    vector<pair<int,int> > temp = mp[sum];
                    bool isFirst = true;
                    for(int k = 0; k < temp.size(); ++k)
                    {
                        if(temp[k].first <= j) continue;
                        if(isFirst || (res.back())[2] != nums[temp[k].first])
                        {
                            res.push_back(vector<int>{nums[i], nums[j], nums[temp[k].first], nums[temp[k].second]});
                            isFirst = false;
                        }
                    }
                }
            }
        }
        return res;
    }
};