// 60 Permutation Sequence
// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Note: Given n will be between 1 and 9 inclusive.

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> f(n,1);
        int f0 = 1;
        string res;
        for(int i = 1; i <= n; ++i)
        {
            f0 = f0*i;
            f[i-1] = f0;
            res += i+'0';
        }
        k--;
        for(int i = 0; i < n; ++i) {
            int r = k%f[n-i-1];
            int s = k/f[n-i-1];
            if(s == 0 && r == 0) return res;
            if(s > 0) {
                for(int j = i-1+s; j > i-1; --j) { //Caution!!! j should start from i-1+s, s the current offset for swap, i start from 1 because k is usually less than fn[i-1]
                    swap(res[j], res[j-1]);
                }
            }
            if(r == 0) return res;
            else k = r;
        }
        return res;
    }
};