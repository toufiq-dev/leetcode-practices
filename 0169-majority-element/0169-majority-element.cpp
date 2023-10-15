class Solution {
public:
    // Optimal solution
    // TC: O(N)
    // SC: O(1)
    int majorityElement(vector<int>& nums) {
        int candidate = -1, votes = 0;

        // find majority candidate
        for(int i = 0; i < nums.size(); i++) {
            if(votes == 0) {
                candidate = nums[i];
                votes = 1;
            } else {
                if(nums[i] == candidate) {
                    votes++;
                } 
                else 
                    votes--;
            }
        }
        
        // find if majority candidate appears more than ⌊n / 2⌋ times.
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == candidate)
                count++;
        }

        if(count > floor(nums.size() / 2)) 
            return candidate;

        return -1;
    }
};