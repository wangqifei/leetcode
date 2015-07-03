// 125 Valid Palindrome
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty() || s.size() == 1) return true;
        int st = 0;
        int ed = s.size();
        while(st < ed) {
            while(st < ed && s[st] == ' ') st++;
            while(st < ed && s[ed] == ' ') ed--;
            while(st < ed && isalnum(s[st]) == false) st++;
            while(st < ed && isalnum(s[ed]) == false) ed--;
            if(s[st] == s[ed] || s[ed]-s[st] == 'A'-'a' || s[ed]-s[st] == 'a'-'A') {
                st++;
                ed--;
            }
            else {
                return false;
            }
        }
        return true;
    }

    //more concise solution from oj leetcode discussion
    bool isPalindrome(string s) {
        int st = 0;
        int ed = s.size();
        while(st < ed) {
            while(st < ed && !isalnum(s[st])) st++;
            while(st < ed && !isalnum(s[ed])) ed--;
            if(toupper(s[st]) != toupper(s[ed])) return false;
            st++;
            ed--;
        }
        return true;
    }
};