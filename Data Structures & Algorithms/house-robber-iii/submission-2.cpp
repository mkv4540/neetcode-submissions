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
    map<pair<TreeNode*, int>, int>mp;
    int max_amount(TreeNode* root, int can_rob = 1){
        if (root == nullptr){
            return 0;
        }
        if (mp[{root, can_rob}])
            return mp[{root, can_rob}];
        int next = max_amount(root->left, 1) + max_amount(root->right, 1);
        if (can_rob){
            int curr = root->val + max_amount(root->left, 0) + max_amount(root->right, 0);
            return mp[{root, can_rob}] = max(curr, next);
        }else{
            return mp[{root, can_rob}] = next;
        }
    }
    int rob(TreeNode* root) {
        return max_amount(root, 1);
    }
};