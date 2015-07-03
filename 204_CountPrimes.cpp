// 204 Count Primes
// Description:

// Count the number of prime numbers less than a non-negative number, n.

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.

// Hint:

// Let's start with a isPrime function. To determine if a number is prime, we need to check if it is not divisible by any number less than n. The runtime complexity of isPrime function would be O(n) and hence counting the total prime numbers up to n would be O(n2). Could we do better?

// Show More Hint 
// Hide Tags Hash Table Math


class Solution {
public:
    int countPrimes(int n) {
        if(n < 3)  return 0;
        vector<bool> mask(n+1, true);
        for(int i = 2; i < n; ++i) {
            if(i*i>n) break;
            if(mask[i] ==  true) {
                int j = 2*i;
                while(j < n) {
                    mask[j] = false;
                    j = j+i;
                }
            }
        }
        int res = 0;
        for(int i = 2; i < n; ++i) {
            if(mask[i]) res++;
        }
        return res;
    }

    //one way iterative solution
    int countPrimes2(int n) {
        if(n<=2) return 0;
        vector<bool> mask(n+1, false);
        int res = 1;
        int upper = sqrt(n);
        for(int i = 3; i < n; i = i+2) {
            if(mask[i] == false) res++;
            if(i>upper) continue;
            for(int j = i*i; j < n; j = j+i) {
                mask[j] = true;
            }
        }
        return res;
    }

    //This solution use pointer instead of vector, the runtime is reduced significantly from 308mm to 26mm. This means that pointer is much faster for accessing than vector
    int countPrimes3(int n) {
        if (n <= 2) return 0;
        double c = sqrt(n);
        bool* bv = new bool[n];
        for(int i = 3; i <= c; i += 2)
            if (!bv[i]) 
                for(int j = i*i, k = i << 1; j < n; j += k)
                    bv[j] = 1;
        int num = 1;
        for(int i = 3; i < n; i += 2)
            if(!bv[i]) num++;
        delete [] bv;
        bv = NULL;
        return num;
    }
};