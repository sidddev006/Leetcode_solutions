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
    int best = INT_MIN;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int left_sum = dfs(root->left);
        left_sum = max(0, left_sum);
        int right_sum = dfs(root->right);
        right_sum = max(right_sum, 0);
        best = max(best, left_sum + right_sum + root->val);
        return max(left_sum, right_sum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return best;
    }
};