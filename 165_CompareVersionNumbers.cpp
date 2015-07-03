// 165 Compare Version Numbers
// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

// Here is an example of version numbers ordering:

// 0.1 < 1.1 < 1.2 < 13.37
// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

// Hide Tags String


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1 = 0;
        int s2 = 0;
        while(s1 < version1.size() && s2 < version2.size()) {
            int e1 = s1;
            while(e1 < version1.size() && version1[e1] != '.') e1++;
            int n1 = stoi(version1.substr(s1, e1-s1).c_str());
            int e2 = s2;
            while(e2 < version2.size() && version2[e2] != '.') e2++;
            int n2 = stoi(version2.substr(s2, e2-s2).c_str());
            if(n1 < n2) return -1;
            else if(n1 > n2) return 1;
            else {
                s1 = e1+1;
                s2 = e2+1;
            }
        }
        while(s1 < version1.size()) { //Caution 1 = 1.0
            int e1 = s1;
            while(e1 < version1.size() && version1[e1] != '.') e1++;
            int n1 = stoi(version1.substr(s1, e1-s1).c_str());
            if(n1 == 0) {
                s1 = e1+1;
            }
            else {
                return 1;
            }
        }
        while(s2 < version2.size()) {
            int e2 = s2;
            while(e2 < version2.size() && version2[e2] != '.') e2++;
            int n2 = stoi(version2.substr(s2, e2-s2).c_str());
            if(n2 == 0) {
                s2 = e2+1;
            }
            else {
                return -1;
            }
        }
        return 0;
    }
};