// 11 Container With Most Water
// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container.

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty()) return 0;
        int i = 0;
        int j = height.size()-1;
        int res = (j-i)*min(height[i], height[j]);
        while(i < j)
        {
            if(height[i]<height[j])  //Caution!!! move the side with lower height
            {
                i++;
            }
            else
            {
                j--;
            }
            int d = j-i;
            int temp = d*min(height[i], height[j]);
            if(temp > res) res = temp;
        }
        return res;
    }
};