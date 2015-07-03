// 174 Dungeon Game
// The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

// Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

// In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


// Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

// For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

// -2 (K)	-3	3
// -5	-10	1
// 10	30	-5 (P)

// Notes:

// The knight's health has no upper bound.
// Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

//idea: determine the minimum cost direction, by min_next = min(right, down), determine the minimum cost for current block by max(1, min_next-d[i][j])
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int h = dungeon.size();
        if(h == 0) return 0;
        int w = dungeon[0].size();
        vector<vector<int> > mat(h, vector<int>(w, 0));
        mat[h-1][w-1] = max(1, 1-dungeon[h-1][w-1]);  //Caution!!! get max between 1 and 1-d[i][j] since 1-d[i][j] might be less than 0
        for(int i = h-2; i >= 0; --i) {
            mat[i][w-1] = max(1, mat[i+1][w-1]-dungeon[i][w-1]);
        }
        for(int i = w-2; i >= 0; --i) {
            mat[h-1][i] = max(1, mat[h-1][i+1]-dungeon[h-1][i]);
        }
        for(int i = h-2; i >= 0; --i) {
            for(int j = w-2; j >= 0; --j) {
                int hp = min(mat[i+1][j], mat[i][j+1]);
                mat[i][j] = max(1, hp-dungeon[i][j]);
            }
        }
        return mat[0][0];
    }
};