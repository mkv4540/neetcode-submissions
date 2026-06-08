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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *visit = root;
        if (visit == nullptr){
            return new TreeNode(val);
        }
        while (visit){
            if (visit->val < val){
                if (!visit->right){
                    visit->right = new TreeNode(val);
                    break;
                }
                visit = visit->right;
            }else{
                if (!visit->left){
                    visit->left = new TreeNode(val);
                    break;
                }
                visit = visit->left;
            }
        }
        return root;
    }
};