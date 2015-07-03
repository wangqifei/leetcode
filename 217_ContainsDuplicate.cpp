// 217 Contains Duplicate Total Accepted: 15859 Total Submissions: 44268 My Submissions Question Solution 
// Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

// Hide Tags Array Hash Table


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return false;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i) {
            if(mp.count(nums[i])) return true;
            else mp.insert(make_pair(nums[i], i));
        }
        return false;
    }

    bool containsDuplicate2(vector<int>& nums) {
    	return nums.size() == set<int>(nums.begin(), nums.end()).size();
    }
};