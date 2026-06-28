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
    void check(TreeNode *root, int &flag, int &prev){
        if (root == nullptr){
            return;
        }
        check(root->left, flag, prev);
        if (prev >= root->val){
            flag = 0;
            return;
        }
        prev = root->val;
        check(root->right, flag, prev);

    }
    bool isValidBST(TreeNode* root) {
        int flag = 1, prev = INT_MIN;
        check (root, flag, prev);
        return flag;
    }
};
