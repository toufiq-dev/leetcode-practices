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
    TreeNode* bstBuilder(vector<int> &nums, int L, int R) {
        if (L > R) return nullptr;
        int M = L + (R - L) / 2;
        auto root = new TreeNode(nums[M]);
        root -> left = bstBuilder(nums, L, M - 1);
        root -> right = bstBuilder(nums, M + 1, R);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bstBuilder(nums, 0, nums.size() - 1);
    }
};;