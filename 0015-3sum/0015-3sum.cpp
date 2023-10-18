class Solution {
    public:
        // TC: O(N)
        // SC: O(N)
        vector<vector<int>> threeSum(vector<int>& nums) {
            // step1: sort the array
            sort(nums.begin(), nums.end());

            vector<vector<int>> triplets;

            // step2: for each element in array apply two-sum
            for(int i = 0; i < nums.size(); i++) {
                int a = nums[i];

                // for every a(prefix), find b, c form  
                // suffix such that, b + c == -a
                int L = i + 1;
                int R = nums.size() - 1;
                int target = -a;

                while(L < R) {
                    if(nums[L] + nums[R] < target)
                        L++;
                    else if (nums[L] + nums[R] > target) 
                        R--;
                    else {
                        // remove duplicates
                        while(L < R && nums[L] == nums[L + 1])
                            L++;
                        while(L < R - 1 && nums[R] == nums[R - 1])
                            R--;

                        triplets.push_back({nums[i], nums[L], nums[R]});
                        L++;
                        R--;
                    }                        
                }

                while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                    i++;
            }

            return triplets;
        }
};