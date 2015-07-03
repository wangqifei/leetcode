// 187 Repeated DNA Sequences
// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

// For example,

// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].
// Hide Tags Hash Table Bit Manipulation

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
using namespace::std;

//the key of this problem is generate your own hash function for each string
//Caution!!! we cannot use more than one hash table in this problem, any additional memory will introduce redundancy in memory and result in MLE
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size()<=10) res;
        int len = s.size();
        unordered_map<int, int> mp;  //Caution!!! the first int is the hash value of each string, the second one is the times of that sequence appears in s
        unsigned char binary_map[26] = {0};
        binary_map['A'-'A'] = 0;
        binary_map['C'-'A'] = 1;
        binary_map['G'-'A'] = 2;
        binary_map['T'-'A'] = 3;
        uint32_t str_mask = 0x000FFFFF;
        string str = s.substr(0,10);
        uint32_t seq_int = 0;
        for(int i = 0; i < 10; ++i) {
            seq_int = seq_int<<2 | binary_map[str[i]-'A'];
        }
        mp.insert(make_pair(seq_int, 1));
        for(int i = 1; i <= len-10; ++i) {
            str = s.substr(i, 10);
            seq_int = seq_int<<2 & str_mask | binary_map[str[9]-'A'];
            if(mp.count(seq_int) && mp[seq_int] == 1) {
                res.push_back(str);
                mp[seq_int]++;
            }
            else {
                mp.insert(make_pair(seq_int, 1));
            }
        }
        return res;
    }

    vector<string> findRepeatedDnaSequences2(string s) {
        unordered_map<size_t, int> mp;
        hash<string> hash_fn;
        vector<string> res;
        for(int i = 0; i < s.size()-9; ++i) {
            if(mp[hash_fn(s.substr(i, 10))]++ == 1) 
                res.push_back(s.substr(i, 10));
        }
        return res;
    }

    vector<string> findRepeatedDnaSequences3(string s) {
        unordered_map<size_t,int> MP;
        hash<string> hash_fn;
        vector<string> ret;

        for(int i = 0; i < int(s.size()) - 9; ++i)
            if(MP[hash_fn(s.substr(i,10))]++ == 1 )
               ret.push_back(s.substr(i,10));

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    string s = "CAAAAAAAAAC";
    Solution mySolution;
    vector<string> res = mySolution.findRepeatedDnaSequences(s);
    for(int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }
    return 0;
}