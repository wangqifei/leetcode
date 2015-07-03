// 219 Contains Duplicate II Total Accepted: 11500 Total Submissions: 44990 My Submissions Question Solution 
// Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

// Hide Tags Array Hash Table
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()) return false;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); ++i) {
            if(mp.find(nums[i]) == mp.end()) {
                mp.insert(make_pair(nums[i], vector<int>(1, i)));
            }
            else {
                for(int j = 0; j < mp[nums[i]].size(); ++j) {
                    if(abs(mp[nums[i]][j]-i)<=k) return true;
                }
                mp[nums[i]].push_back(i);
            }
        }
        return false;
    }
    //eaiser solution, only the last index is recorded for each value
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()<1) return false;
        unordered_map<int, int > mp;
        for(int i = 0; i < nums.size(); ++i) {
            if(mp.count(nums[i])) {
                if(i - mp[nums[i]] <= k) return true;
                else mp[nums[i]] = i;
            }
            else {
                mp.insert(make_pair(nums[i], i));
            }
        }
        return false;
    }
};