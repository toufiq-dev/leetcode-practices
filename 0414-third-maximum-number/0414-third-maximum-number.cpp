class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int element = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] != nums[i])
                element++;

            if (element == 3)
                return nums[i];
        }

        return nums[0];
    }
};