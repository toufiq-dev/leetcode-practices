class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        int leftProduct = 1;
        for(int i = 0; i < nums.size(); i++) {
            ans[i] *= leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return ans;
    }
};