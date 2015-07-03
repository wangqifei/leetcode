//6 ZigZag Conversion 
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty() || s.size()<numRows || numRows == 1) return s;
        int stride = 2*numRows-2;
        string res;
        for(int i = 0; i < numRows; ++i)
        {
            int index = 0;
            if(i == 0)
            {
                while(index < s.size())
                {
                    res += s[index];
                    index += stride;
                }
                continue;
            }
            if(i == numRows-1)
            {
                index += numRows-1;
                while(index < s.size())
                {
                    res += s[index];
                    index += stride;
                }
                continue;
            }
            while(index < s.size())
            {
                int ind1 = index+i;
                if(ind1<s.size()) res+=s[ind1];
                int ind2 = index+stride-i;
                if(ind2<s.size()) res+=s[ind2];
                index += stride;
            }
        }
        return res;
    }
};