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
    int sum;
    void dfs(TreeNode *n){
        if(n->left!=nullptr){
            if(n->left->left==nullptr && n->left->right == nullptr)
                sum+=n->left->val;
            dfs(n->left);
        }
        if(n->right !=nullptr){
            dfs(n->right);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum=0;
        dfs(root);
        return sum;
    }
};