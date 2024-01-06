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
    bool validateBST(TreeNode* root, TreeNode* l_min, TreeNode* r_max) {
        if(root == nullptr) return true;
        if((l_min && l_min -> val >= root -> val) || (r_max && root -> val >= r_max -> val)) 
            return false;
        
        return validateBST(root -> left, l_min, root) &&
               validateBST(root -> right, root, r_max);
    }
    bool isValidBST(TreeNode* root) {
        return validateBST(root, nullptr, nullptr);
    }
};