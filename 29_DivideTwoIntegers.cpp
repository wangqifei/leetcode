// 29 Divide Two Integers 
// Divide two integers without using multiplication, division and mod operator.

// If it is overflow, return MAX_INT.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        if(divisor == 1) return dividend;
        if(divisor == -1 && dividend == INT_MAX) return -INT_MAX;
        if(divisor == -1 && dividend == INT_MIN) return INT_MAX;
        bool sign = true;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = false;
        long long absdivisor = abs((long long) divisor);
        long long absdividend = abs((long long) dividend);
        int res = 0;
        long long pow_sum = absdivisor;
        int pow = 1;
        while(absdividend > pow_sum)
        {
            pow_sum = pow_sum<<1;
            pow = pow<<1;
        }
        while(absdividend >= absdivisor)
        {
            while(absdividend >= pow_sum)
            {
                absdividend -= pow_sum;
                res += pow;
            }
            pow_sum >>= 1;
            pow >>= 1;
        }
        if(sign) return res;
        else return -res;
    }
};