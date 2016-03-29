/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        map<int, vector<int>> maps;
        pair<TreeNode*, int> cur;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            cur = q.front(), q.pop();
            maps[cur.second].push_back(cur.first->val);
            if(cur.first->left)
                q.push(make_pair(cur.first->left, cur.second - 1));
            if(cur.first->right)
                q.push(make_pair(cur.first->right, cur.second + 1));
        }
        for(map<int, vector<int>>::iterator it = maps.begin(); it != maps.end(); ++it)
            res.push_back(it->second);
        return res;
        
    }
};
