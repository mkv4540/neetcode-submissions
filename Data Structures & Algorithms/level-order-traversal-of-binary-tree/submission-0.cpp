/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        vector<vector<TreeNode*>>ans;
        if (root == nullptr){
            return {};
        }
        q.push({root, 0});
        while (q.size()){
            pair <TreeNode*, int>p = q.front();
            if (ans.size() > p.second){
                ans[p.second].push_back(p.first);
            }else{
                ans.push_back({p.first});
            }
            if (p.first->left){
                q.push({p.first->left, p.second + 1});
            }
            if (p.first->right){
                q.push({p.first->right, p.second + 1});
            }
            q.pop();
        }
        vector<vector<int>>res;
        for (vector<TreeNode*>v : ans){
            res.push_back({});
            for (TreeNode* x : v){
                res.back().push_back(x->val);
            }
        }
        return res;
    }
};
