class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyeer-Moore algorithm
        int element = nums[0], votes = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == element) {
                ++votes;
            } else {
                --votes;
                if (votes = 0) {
                    element = nums[i];
                    ++votes;
                }
            }
        }

        // verify majority element
        int count = 0;
        for (int num : nums) {
            ++count;
        }

        if (count > nums.size() / 2) {
            return element;
        }

        return -1; 
    }
};