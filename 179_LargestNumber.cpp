// 179 Largest Number
// Given a list of non negative integers, arrange them such that they form the largest number.

// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

// Hide Tags Sort


class Solution {
public:
    static bool cmp(string s1, string s2) {
        return s1+s2 > s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int i = 0; i < nums.size(); ++i) {
            str.push_back(to_string(nums[i]));
        }
        sort(str.begin(), str.end(), cmp);
        string res;
        for(int i = 0; i < str.size(); ++i) {
            res += str[i];
        }
        if(res[0] == '0' && res.size()>1) res = "0";
        return res;
    }
};