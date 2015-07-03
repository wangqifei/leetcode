// 118 Pascal's Triangle
// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if(numRows <= 0) return res;
        vector<int> row(1,1);
        res.push_back(row);
        for(int i = 1; i < numRows; ++i) {
            row = res[i-1];
            vector<int> cur_row(i+1, 1);
            for(int j = 1; j < i; ++j) {
                cur_row[j] = row[j-1]+row[j];
            }
            res.push_back(cur_row);
        }
        return res;
    }
};