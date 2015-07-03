// Pow(x, n)
// Implement pow(x, n).

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        if(n == 1) return x;
        bool sign = n>0;
        n = sign?n:-n;
        double s = myPow(x,n/2);
        double res = s*s;
        if(n%2) res = res*x;
        if(sign) return res;
        else return 1/res;
    }

    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        if(n == 1) return x;
        bool sign = n>0;
        n = sign?n:-n;
        double res = 1;
        while(n > 0) {
            if(n%2) res *= x;
            n >>= 1;
            x = x*x;
        }
        if(sign) return res;
        else return 1/res;
    }
};