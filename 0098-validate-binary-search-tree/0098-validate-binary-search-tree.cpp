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
private:
    bool validate(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (node == nullptr) {
            return true;
        }

        if (minNode != nullptr && node->val <= minNode->val) {
            return false;
        }

        if (maxNode != nullptr && node->val >= maxNode->val) {
            return false;
        }

        return validate(node->left, minNode, node) && 
               validate(node->right, node, maxNode);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};