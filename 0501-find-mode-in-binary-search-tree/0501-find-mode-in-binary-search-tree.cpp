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
    vector<int> modes;
    int current_val = 0;
    int current_count = 0;
    int max_count = 0;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (current_count == 0 || root->val != current_val) {
            current_val = root->val;
            current_count = 1;
        } else {
            current_count++;
        }

        if (current_count > max_count) {
            max_count = current_count;
            modes = {current_val};
        } else if (current_count == max_count) {
            modes.push_back(current_val); 
        }
        inorder(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        modes.clear();
        current_count = 0;
        max_count = 0;
        inorder(root);
        return modes;
    }
};