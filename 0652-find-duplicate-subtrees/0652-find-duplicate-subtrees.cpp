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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtreeCount;  // To store the count of each subtree
        unordered_set<TreeNode*> result;  // To store the root of duplicate subtrees
        postorder(root, subtreeCount, result);
        return vector<TreeNode*>(result.begin(), result.end());
    }

private:
    // Helper function for postorder traversal
    string postorder(TreeNode* root, unordered_map<string, int>& subtreeCount, unordered_set<TreeNode*>& result) {
        if (!root) return "#";  // Represent null nodes with '#'

        // Traverse left and right subtrees
        string left = postorder(root->left, subtreeCount, result);
        string right = postorder(root->right, subtreeCount, result);

        // Construct unique identifier for the current subtree
        string subtree = to_string(root->val) + "," + left + "," + right;

        // Update count in the hash table
        subtreeCount[subtree]++;

        // If count is 2, it means we have encountered this subtree before
        // Add the root to the result set
        if (subtreeCount[subtree] == 2) {
            result.insert(root);
        }

        return subtree;
    }
};