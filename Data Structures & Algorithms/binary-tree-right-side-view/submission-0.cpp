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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        vector<vector<int>>level_order;
        vector<int>ans;
        while (q.size()){
            pair<TreeNode*, int>front = q.front();
            if (ans.size() <= front.second){
                ans.push_back(front.first->val);
            }
            q.pop();
            if (front.first->right){
                q.push({front.first->right, front.second + 1});
            }
            if (front.first->left){
                q.push({front.first->left, front.second + 1});
            }
        }
        return ans;
    }
};
