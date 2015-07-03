// 220 Contains Duplicate III Total Accepted: 4690 Total Submissions: 30576 My Submissions Question Solution 
// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

// Hide Tags Binary Search Tree

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2) return false;
        if(k == 0) return true;
        vector<int> vec;
        int stride = k;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < vec.size(); ++j) {
                if(abs(vec[j]-nums[i]) < t) return true;
            }
            if(vec.size()<stride) {
                vec.push_back(nums[i]);
            }
            else {
                vec.erase(vec.begin());
                vec.push_back(nums[i]);
            }
        }
        vec.clear();
        for(int i = nums.size()-1; i >= 0; --i) {
            for(int j = 0; j < vec.size(); ++j) {
                if(abs(vec[j]-nums[i]) < t) return true;
            }
            if(vec.size()<stride) {
                vec.push_back(nums[i]);
            }
            else {
                vec.erase(vec.begin());
                vec.push_back(nums[i]);
            }
        }
        return false;
    }

    //using a map to store the value and position information
    //keep the largest index difference in all the numbers in the map less than k, otherwise, remove the frontal one
    //find the one within the value range by lower_bound function of map
    bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
        if(nums.size()<2 || k == 0) return false; //Caution, if k = 0, nums[i] and nums[j] will be the same one, they are not two idstinct indices
        map<long long, int> mp;
        int st = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i-st>k && mp[nums[st]] == st)
                mp.erase(nums[st++]);
            auto mit = mp.lower_bound(nums[i]-t);
            if(mit != mp.end() && mit->first-nums[i]<=t && (i - mit->second) <= k) return true;
            mp[nums[i]] = i;
        }
        return false;
    }

    bool containsNearbyAlmostDuplicate3(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k == 0)
            return false;
        deque<int> windows_deq;
        multiset<long> windows;
        for (int i = 0; i < nums.size(); i++) {
            if (windows.size() > k) {
                int num = windows_deq.front();
                windows_deq.pop_front();
                windows.erase(windows.find(num));
            }
            auto it = windows.lower_bound((long)nums[i] - (long)t);
            if (it == windows.end() || *it > (long)nums[i] + (long)t) {
                // not found
                windows_deq.push_back(nums[i]);
                windows.insert(nums[i]);
            }
            else return true;
        }
        return false;
    }
};