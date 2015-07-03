// 190 Reverse Bits
// Reverse bits of a given 32 bits unsigned integer.

// For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

// Follow up:
// If this function is called many times, how would you optimize it?

// Related problem: Reverse Integer

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

// Hide Tags Bit Manipulation


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; ++i) {  //Caution!!! we need to reverse all the bit, if n = 1, means n = 0x00000001
            res = (res<<1)+n%2; //Caution!!!, res<<1+1 means res<<2, + has higher priority than << and >>
            n = n/2;
        }
        return res;
    }
};