// Plus One
// Given a non-negative number represented as an array of digits, plus one to the number.

// The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        if(digits.empty()) return res;
        reverse(digits.begin(), digits.end());
        int c = 1;
        for(int i = 0; i < digits.size(); ++i) {
            int n = digits[i]+c;
            res.push_back(n%10);
            c = n/10;
        }
        if(c) res.push_back(c);
        reverse(res.begin(), res.end());
        return res;
    }

    //Complexity is almost the same
    vector<int> plusOne2(vector<int>& digits) {
        vector<int> res;
        if(digits.empty()) return res;
        reverse(digits.begin(), digits.end());
        int c = 1;
        int i = 0;
        while(i < digits.size()) {
            int n = digits[i]+c;
            res.push_back(n%10);
            c = n/10;
            i++;
            if(c == 0) break;
        }
        if(c) res.push_back(c);
        else res.insert(res.end(), digits.begin()+i, digits.end());
        reverse(res.begin(), res.end());
        return res;
    }
};