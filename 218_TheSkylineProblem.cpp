// 218 The Skyline Problem Total Accepted: 2507 Total Submissions: 15459 My Submissions Question Solution 
// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

//  Buildings  Skyline Contour
// The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

// For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

// The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

// For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

// Notes:

// The number of buildings in any input list is guaranteed to be in the range [0, 10000].
// The input list is already sorted in ascending order by the left x position Li.
// The output list must be sorted by the x position.
// There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
// Credits:
// Special thanks to @stellari for adding this problem, creating these two awesome images and all test cases.

// Hide Tags Divide and Conquer Heap


class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > res;
        if(buildings.empty()) return res;
        priority_queue<pair<int, int> > q;
        int cur_building = 0;
        int cur_x = 0;
        int cur_h = -1;
        int len = buildings.size();
        while(cur_building < len || q.empty() == false) {
            cur_x = q.empty()?buildings[cur_building][0]:q.top().second;
            
            if(cur_building>=len || buildings[cur_building][0] > cur_x) {
                while(q.empty() == false && q.top().second<=cur_x) q.pop();
            }
            else {
                cur_x = buildings[cur_building][0];
                while(cur_building<len && buildings[cur_building][0] == cur_x) {
                    q.push(make_pair(buildings[cur_building][2], buildings[cur_building][1]));
                    cur_building++;
                }
            }
            cur_h = q.empty()?0:q.top().first;
            if(res.empty() || res.back().second!=cur_h) res.push_back(make_pair(cur_x, cur_h));
        }
        return res;
    }
};