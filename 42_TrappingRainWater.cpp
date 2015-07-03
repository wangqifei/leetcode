// 42 Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

class Solution {
public:
    int trap2(vector<int>& height)
    {
        int secHeight = 0;
        int left = 0;
        int right = height.size()-1;
        int res = 0;
        while(left < right)
        {
            if(height[left]<height[right])
            {
                secHeight = max(secHeight, height[left]);
                res += secHeight - height[left];
                left++;
            }
            else{
                secHeight = max(secHeight, height[right]);
                res += secHeight - height[right];
                right--;
            }
        }
        return res;
    }
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        int n = height.size();
        vector<int> lb(n);
        vector<int> rb(n);
        int temp_max = 0;
        for(int i = 0; i < n; ++i)
        {
            temp_max = max(temp_max, height[i]);
            lb[i] = temp_max;
        }
        temp_max = 0;
        for(int i = n-1; i >= 0; --i)
        {
            temp_max = max(temp_max, height[i]);
            rb[i] = temp_max;
        }
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            res += min(lb[i],rb[i])-height[i];
        }
        return res;
    }
};