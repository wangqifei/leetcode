// 133 Clone Graph
// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


// OJ's undirected graph serialization:
// Nodes are labeled uniquely.

// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.

// The graph has a total of three nodes, and therefore contains three parts as separated by #.

// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
// Visually, the graph looks like the following:

//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/
// Hide Tags Depth-first Search Breadth-first Search Graph


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // BFS solution
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        queue<UndirectedGraphNode*> q;
        mp[node] = new UndirectedGraphNode(node->label);
        q.push(node);
        while(q.empty() == false) {
            UndirectedGraphNode* ref_node = q.front();
            q.pop();
            for(auto next_node:ref_node->neighbors) {
                if(mp.find(next_node) == mp.end()) {
                    mp[next_node] = new UndirectedGraphNode(next_node->label);
                    q.push(next_node);  //Caution!!! only for the new node, we need to push the next_node into queue, otherwise, it will generate infinite loop for the loop node in the graph
                }
                mp[ref_node]->neighbors.push_back(mp[next_node]);
            }
        }
        return mp[node];
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;

    //DFS solution
    UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        if(mp.find(node) == mp.end()) {
            mp[node] = new UndirectedGraphNode(node->label);
            for(auto next_node:node->neighbors) {
                mp[node]->neighbors.push_back(cloneGraph(next_node));
            }
        }
        return mp[node];
    }
};