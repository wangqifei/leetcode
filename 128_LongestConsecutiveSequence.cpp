// 128 Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.

class Solution {
public:
    //solution using unordered_map
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res = 0;
        for(int i=0; i < nums.size(); ++i) {
            if(mp[nums[i]]) continue;
            mp[nums[i]] = mp[nums[i]-1]+mp[nums[i]+1]+1;
            mp[nums[i]-mp[nums[i]-1]] = mp[nums[i]];
            mp[nums[i]+mp[nums[i]+1]] = mp[nums[i]];
            res = max(res, mp[nums[i]]);
        }
        return res;
    }

    //solution using unordered_set, even with more operation, but a little faster than the previous one
    int longestConsecutive2(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(num_set.find(nums[i])!=num_set.end()) {
                int cur = nums[i];
                int cur_count = 1;
                num_set.erase(nums[i]);
                while(num_set.find(++cur) != num_set.end()) {
                    num_set.erase(cur);
                    cur_count++;
                }
                cur = nums[i];
                while(num_set.find(--cur) != num_set.end()) {
                    num_set.erase(cur);
                    cur_count++;
                }
                if(cur_count > res) res = cur_count;
            }
        }
        return res;
    }
};