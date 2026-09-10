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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode* left_node = dfs(root->left,p,q);
        TreeNode* right_node = dfs(root->right,p,q);
        if(left_node != NULL && right_node != NULL) return root;
        if(left_node != NULL) return left_node;
        if(right_node != NULL) return right_node;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};