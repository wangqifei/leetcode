// 200 Number of Islands
// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// 11110
// 11010
// 11000
// 00000
// Answer: 1

// Example 2:

// 11000
// 11000
// 00100
// 00011
// Answer: 3

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.

// Hide Tags Depth-first Search Breadth-first Search
template <typename T,unsigned S>
inline unsigned arraysize(const T (&v)[S]) { return S; }

#include <vector>
#include <string>
using namespace::std;
class Solution {
public:
    //DFS solution
    void traverse(vector<vector<char> >& grid, int i, int j, int h, int w) {
        grid[i][j] = '0';
        if(i<h-1 && grid[i+1][j] == '1') {
            traverse(grid, i+1, j, h, w);
        }
        if(i>0 && grid[i-1][j] == '1') {
            traverse(grid, i-1, j, h, w);
        }
        if(j>0 && grid[i][j-1] == '1') {
            traverse(grid, i, j-1, h, w);
        }
        if(j<w-1 && grid[i][j+1] == '1'){
            traverse(grid, i, j+1, h, w);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        if(h == 0) return 0;
        int w = grid[0].size();
        int res = 0;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(grid[i][j] == '1') {
                    traverse(grid, i, j, h, w);
                    res++;
                }
            }
        }
        return res;
    }

    //BFS solution
    int numIslands2(vector<vector<char>>& grid) {
        int h = grid.size();
        if(h == 0) return 0;
        int w = grid[0].size();
        int res = 0;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(grid[i][j] == '1') {
                    res++;
                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';
                    while(q.empty() == false) {
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();
                        if(y>0 && grid[y-1][x] == '1') {
                            q.push(make_pair(y-1,x));
                            grid[y-1][x] = '0'; //Caution!!! if set the grid element to 0 later, some will be duplicated set to '0', results in TLE
                        }
                        if(y<h-1 && grid[y+1][x] == '1') {
                            q.push(make_pair(y+1,x));
                            grid[y+1][x] = '0';
                        }
                        if(x>0 && grid[y][x-1] == '1') {
                            q.push(make_pair(y, x-1));
                            grid[y][x-1] = '0';
                        } 
                        if(x<w-1 && grid[y][x+1] == '1') {
                            q.push(make_pair(y, x+1));
                            grid[y][x+1] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string A[] = {  "11111011111111101011",
                    "01111111111110111110",
                    "10111001101111111111",
                    "11110111111111111111",
                    "10011111111111111111",
                    "10111111011101110111",
                    "01111111111101101111",
                    "11111111111101111011",
                    "11111111110111111111",
                    "11111111111111111111",
                    "01111111011111111111",
                    "11111111111111111111",
                    "11111111111111111111",
                    "11111011111110111111",
                    "10111110111011110111",
                    "11111111111101111110",
                    "11111111111110111100",
                    "11111111111111111111",
                    "11111111111111111111",
                    "11111111111111111111"};

    int h = 20;
    int w = 20;
    vector<vector<char> > grid(h, vector<char>(w));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            grid[i][j] = A[i][j];
        }
    }
    return 0;
}