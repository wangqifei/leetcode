// 135 Candy
// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

// Hide Tags Greedy


class Solution {
public:
    //this is my solution, better than the following solution
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        if(sz <= 0) return 0;
        if(sz == 1) return 1;
        vector<int> num(sz,1);
        for(int i = 1; i < sz; ++i) {
            if(ratings[i-1]<ratings[i])  //in this iteration, the left are always equal to the right
                num[i] = num[i-1]+1;
        }
        for(int i = sz-1; i > 0; --i) {
            if(ratings[i-1]>ratings[i] && num[i-1] <= num[i])
                num[i-1] = num[i]+1;
        }
        int res = 0;
        for(int i = 0; i < sz; ++i) {
            res += num[i];
        }
        return res;
    }
    //this solution requires more space and a little more time
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        if(sz <= 0) return 0;
        if(sz == 1) return 1;
        vector<int> l(sz,1);
        vector<int> r(sz,1);
        for(int i = 1; i < sz; ++i) {
            if(ratings[i]>ratings[i-1]) 
                l[i] = l[i-1]+1;
        }
        for(int i = sz-1; i > 0; --i) {
            if(ratings[i]<ratings[i-1])
                r[i-1] = r[i]+1;
        }
        int res = 0;
        for(int i = 0; i < sz; ++i) {
            res += max(l[i],r[i]);
        }
        return res;
    }
};