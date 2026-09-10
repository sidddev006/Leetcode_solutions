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
//balanced -> depth of two subtree never differ more than one
    int traverse(TreeNode* root){
        if(root == NULL) return 0;
        int left_depth = traverse(root->left);
        int right_depth = traverse(root->right);
        if(right_depth==-1||left_depth==-1) return -1;
        if(abs(right_depth - left_depth) > 1) return -1;
        return 1+ max(right_depth, left_depth);
    }
    bool isBalanced(TreeNode* root) {
        if(traverse(root) == -1) return false;
        return true;
    }
};