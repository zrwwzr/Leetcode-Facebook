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
    UndirectedGraphNode* dfs(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &map){
        if(!node) return node;
        if(map.find(node) == map.end()){
            UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
            map[node] = newNode;
            for(int i = 0; i < node->neighbors.size(); ++i)
                newNode->neighbors.push_back(dfs(node->neighbors[i], map));
        }
        return map[node];
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        return dfs(node, map);
        
    }
};
