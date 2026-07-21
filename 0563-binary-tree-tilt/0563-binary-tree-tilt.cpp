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
    int total_tilt = 0;
    int calculateSubtreeSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_sum = calculateSubtreeSum(root->left);
        int right_sum = calculateSubtreeSum(root->right);

        total_tilt += abs(left_sum - right_sum);
        return root->val + left_sum + right_sum;
    }

public:
    int findTilt(TreeNode* root) {
        total_tilt = 0;            
        calculateSubtreeSum(root);   
        return total_tilt;  
    }
};