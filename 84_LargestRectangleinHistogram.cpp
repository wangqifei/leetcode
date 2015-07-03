// Largest Rectangle in Histogram
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


// The largest rectangle is shown in the shaded area, which has area = 10 unit.

// For example,
// Given height = [2,1,5,6,2,3],
// return 10.

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if(height.empty()) return 0;
        int res = 0;
        stack<int> st;
        height.push_back(0);
        int i = 0;
        while(i < height.size()) {
            if(st.empty() || height[i] > height[st.top()]) {
                st.push(i);
                i++;
            }
            else {
                int temp = st.top();
                st.pop();
                res = max(res, height[temp]*(st.empty()?i:(i-st.top()-1)));
            }
        }
        return res;
    }
};