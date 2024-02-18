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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        map<int, int> nodeToIndex;
        createMapping(nodeToIndex, inorder);
        TreeNode* ans = treeBuilder(preorder, inorder, preorderIndex, 0, inorder.size() - 1, nodeToIndex);
        return ans;
    }
private:
    TreeNode* treeBuilder(vector<int>& preorder, vector<int>& inorder, int& preorderIdx, 
    int inorderStart, int inorderEnd, map<int, int>& nodeToIndex) {
        // base case
        if (preorderIdx > preorder.size() - 1 || inorderStart > inorderEnd)
            return nullptr;
        
        int element = preorder[preorderIdx++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        root -> left = treeBuilder(preorder, inorder, preorderIdx, inorderStart, position - 1, nodeToIndex);
        root -> right = treeBuilder(preorder, inorder, preorderIdx, position + 1, inorderEnd, nodeToIndex);

        return root;
    }
    void createMapping(map<int, int>& nodeToIndex, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }
};