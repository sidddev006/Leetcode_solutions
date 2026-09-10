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
    int count_good = 0;
    void traverse(TreeNode* root, int max_so_far){
        if(root == NULL) return;
        if(root->val >= max_so_far) count_good++;
        max_so_far = max(max_so_far, root->val);
        traverse(root->left, max_so_far);
        traverse(root->right, max_so_far);
    }
    int goodNodes(TreeNode* root) {
        traverse(root, INT_MIN);
        return count_good;
    }
};