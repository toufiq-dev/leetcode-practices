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
    int counter, result;
    void inorderDFS(TreeNode* root, int k) {
        if(root == nullptr) return;
        inorderDFS(root -> left, k);
        ++counter;
        if(counter == k) result = root -> val;
        inorderDFS(root -> right, k); 
    }
    int kthSmallest(TreeNode* root, int k) {
        inorderDFS(root, k);
        return result;
    }
};