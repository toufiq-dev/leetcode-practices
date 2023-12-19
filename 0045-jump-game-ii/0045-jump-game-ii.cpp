class Solution {
public:
    // TC: O(n), n = |nums|
    // SC: O(1)
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int furthest  = 0;
        int memo = 0;
        int total_jump = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            furthest  = max(furthest , nums[i] + i);
            if(i == memo) {
                ++total_jump;
                memo = furthest ;
            }
        }

        return total_jump;
    }
};