// 71 Simplify Path 
// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// click to show corner cases.

// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        if(path.empty()) return res;
        vector<string> folder;
        int i = 0;
        while(i<path.size()) {
            while(i< path.size() && path[i] == '/') i++;
            if(i == path.size()) break;
            int st = i;
            while(i < path.size() && path[i] != '/') i++;
            int ed = i;
            string folderName = path.substr(st, ed-st);
            if(folderName == "..") {
                if(folder.empty() == false) folder.pop_back();
            }
            else if(folderName == ".") continue;
            else folder.push_back(folderName);
        }
        if(folder.empty()) return "/";
        for(int i = 0; i < folder.size(); ++i) {
            res += '/'+folder[i];
        }
        return res;
    }
};