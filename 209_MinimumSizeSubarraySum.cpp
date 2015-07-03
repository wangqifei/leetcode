// 209 Minimum Size Subarray Sum Total Accepted: 7661 Total Submissions: 33326 My Submissions Question Solution 
// Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.

// click to show more practice.

// Credits:
// Special thanks to @Freezen for adding this problem and creating all test cases.

// Hide Tags Array Two Pointers Binary Search


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() <= 0) return 0; 
        int st = 0;
        int ed = 0;
        int sum = 0;
        int res = nums.size()+1;
        while(ed < nums.size()) {
            while(ed < nums.size() && sum < s) { 
                sum += nums[ed]; 
                ed++; 
            }
            while(st < ed && sum >= s) {
                sum -= nums[st];
                st++;
            }
            res = min(res, ed-st+1);
        }
        if(res == nums.size()+1) return 0;
        else return res;
    }

    //NlogN solution, but still some bugs there
    int minSubArrayLen2(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> sums(nums);
        int res = nums.size()+1;
        for(int i = 1; i < nums.size(); ++i) {
            sums[i] = sums[i-1]+nums[i-1];
        }
        for(int i = 0; i < nums.size(); ++i) {
            int st = i;
            int ed = nums.size()-1;
            int off = i=0?0:sums[i-1];
            while(st<=ed) {
                int md = st+(ed-st)/2;
                if(sums[md]-off >= s) {
                    ed = md-1;
                }
                else {
                    st = md+1;
                }
            }
            if(st == nums.size()) break;
            res = min(res, st-i);
        }
        if(res == nums.size()+1) return 0;
        else return res;
    }

    //this solution is not that efficient, but acceptable and easy to understand. reverse the original to check the longest prefix palindrome
    //idea is from oj leetcode
    string shortestPalindrome(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size(),l;
        for(l=n;l>=0;l--)
        {
            if(s.substr(0,l)==s2.substr(n-l))
                break;
        }
        return s2.substr(0,n-l)+s;
    }
};