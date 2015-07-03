// 206 Course Schedule Total Accepted: 7321 Total Submissions: 34036 My Submissions Question Solution 
// There are a total of n courses you have to take, labeled from 0 to n - 1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// For example:

// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

// click to show more hints.

// Hints:
// This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
// Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
// Topological sort could also be done via BFS.
// Hide Tags Depth-first Search Breadth-first Search Graph Topological Sort


class Solution {
public:
    //BFS solution
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses <= 0) return false;
        vector<unordered_set<int> > forward_map(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i = 0; i < prerequisites.size(); ++i) {
            forward_map[prerequisites[i].second].insert(prerequisites[i].first);
        }
        for(int i = 0; i < forward_map.size(); ++i) {
            for(auto it:forward_map[i]) {
                ++indegree[it];
            }
        }
        for(int i = 0; i < numCourses; ++i) {
            int k;
            for(k = 0; k < numCourses && indegree[k] != 0; ++k);
            if(k == numCourses) return false;
            indegree[k] = -1;
            for(auto it:forward_map[k]) {
                --indegree[it];
            }
        }
        return true;
    }


    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses <= 0) return false;
        vector<unordered_set<int> > forward_map(numCourses);
        for(int i = 0; i < prerequisites.size(); ++i) {
            forward_map[prerequisites[i].second].insert(prerequisites[i].first);
        }
        vector<bool> perm_visit(numCourses, false);
        for(int i = 0; i < numCourses; ++i) {
            if(perm_visit[i] == false) {
                vector<bool> temp_visit(numCourses,false);
                if(dfs(forward_map, i, temp_visit, perm_visit)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(vector<unordered_set<int> > forward_map, int c, vector<bool>& temp_visit, vector<bool>& perm_visit) {  //Caution, the forward_map should be a reference, since it might be a large bulk of memory for the large data test case, it will require more time to allocate a new vector<unordered_set>> when passing by argument
        perm_visit[c] = true;
        temp_visit[c] = true;
        for(auto it:forward_map[c]) {
            if(temp_visit[it] == true || dfs(forward_map, it, temp_visit, perm_visit)) return true;
        }
        temp_visit[c] = false;
        return false;
    }


    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses <= 0) return false;
        vector<unordered_set<int> > forward_map(numCourses);
        for(int i = 0; i < prerequisites.size(); ++i) {
            forward_map[prerequisites[i].second].insert(prerequisites[i].first);
        }
        unordered_set<int> visited;
        vector<bool> flag(numCourses, false);
        for(int i = 0; i < numCourses; ++ i)
            if(!flag[i])
                if(dfs(forward_map, visited, i, flag))
                    return false;
        return true;
    }
    bool dfs(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag)
    {
        flag[b] = true;
        visited.insert(b);
        for(auto it = matrix[b].begin(); it != matrix[b].end(); ++ it)
            if(visited.find(*it) != visited.end() || dfs(matrix, visited, *it, flag))
                return true;
        visited.erase(b);
        return false;
    }
};