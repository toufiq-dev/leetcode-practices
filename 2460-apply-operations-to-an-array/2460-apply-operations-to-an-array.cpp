class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
                ++i; 
            }
        }

        int writer = 0;
        for (int reader = 0; reader < nums.size(); ++reader) {
            if (nums[reader] != 0) {
                nums[writer] = nums[reader];
                ++writer;
            }
        }

        while (writer < nums.size()) {
            if (nums[writer] != 0) {
                nums[writer] = 0;
            }
            ++writer;
        }

        return nums;
    }
};