class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int L = 0, R = 0; R < nums.size(); ++R) {
            if (nums[R] != 0) {
                swap(nums[L], nums[R]);
                L++;
            }
        }
    }
};