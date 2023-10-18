class Solution {
public:
    // TC: O(N ^ 3)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // step1: sort the array
        sort(nums.begin(), nums.end());
        vector<vector<int>> quadruplets;

        // step2: apply three sum on each element
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                int a = nums[i] + nums[j];
                int L = j + 1;
                int R = nums.size() - 1;
                long long newTarget = static_cast<long long>(target) - a;

                while(L < R) {
                    if(nums[L] + nums[R] < newTarget)
                        L++;
                    else if(nums[L] + nums[R] > newTarget) 
                        R--;
                    else {
                        while(L + 1 < R && nums[L] == nums[L + 1])
                            L++;
                        while(L < R - 1 && nums[R] == nums[R - 1])
                            R--;

                        quadruplets.push_back({nums[i], nums[j], nums[L], nums[R]});
                        L++;
                        R--;
                    }
                }
                
                while(j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++;
            }

            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }

        return quadruplets;
    }
};