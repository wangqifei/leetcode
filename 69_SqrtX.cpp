// 69 Sqrt(x)
// Implement int sqrt(int x).

// Compute and return the square root of x.
#include <iostream>
#include <stdlib.h>
using namespace::std;
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        double x0 = 1;  //Caution!!! x0 and x1 should be double. if x0 and x1 are int, the loop will not stop
        double x1 = x;
        while(abs(x1-x0)>=1) {
            x0 = x1;
            x1 = (x0+x/x0)/2;
        }
        return (int)x1;
    }
    int mySqrt2(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1; //Caution, x==1 should be dealed seperately. Otherwise, if x == 1, the code return 0;
        int l = 0;
        int h = x;
        while(h-l>1){
            long long m = l+(h-l)/2;  //Caution!!! m*m may overflow, so we need to use long long
            if(m*m>x) h = m;
            else if(m*m<x) l = m;
            else return m;
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{
    int x = 2147395599;
    Solution mySolution;
    int res = mySolution.mySqrt2(x);
    cout<<res<<endl;
    return 0;
}