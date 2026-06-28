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
    void find_nodes(TreeNode* root, int curr_max, int &count){
        if (root == nullptr){
            return;
        }
        if (curr_max <= root->val){
            count++;
            curr_max = root->val;
        }
        find_nodes(root->left, curr_max, count);
        find_nodes(root->right, curr_max, count);
    }
    int goodNodes(TreeNode* root) {
        int curr_max = root->val - 1, count = 0;
        find_nodes(root, curr_max, count);
        return count;
    }
};
