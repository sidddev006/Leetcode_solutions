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
    int count = 0;
    vector<int> traverse(TreeNode* root){
        int sum= 0, count_of_nodes = 0;
        if(root == NULL) return {0,0};
        vector<int> leftTree = traverse(root->left);
        vector<int> rightTree = traverse(root->right);
        int total_sum = leftTree[0] + rightTree[0] + root->val;
        int total_count_of_nodes = leftTree[1] + rightTree[1]+1;
        int average = total_sum / total_count_of_nodes;
        if(average == root->val) count++;
        return {total_sum, total_count_of_nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return count;
    }
};