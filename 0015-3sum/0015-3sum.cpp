class Solution {
public:
    // TC: O(N ^ 2)
    // SC: O(N)
    vector<vector<int>> threeSum(vector<int>& nums) {
        // step1: sort(nums)
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;

        // step2: iterate through nums,
        // for every nums member run two sum operation
        // igonre duplicates
        for(int i = 0; i < nums.size(); i++) {
            int a = nums[i];

            // for every a(prefix), find b, c form  
            // suffix such that, b + c == -a
            int L = i + 1;
            int R = nums.size() - 1;
            int target = -a;
            while(L < R) {
                int b = nums[L];
                int c = nums[R];
                if(b + c < target) 
                    L++;
                else if(b + c > target)
                    R--;
                else {
                    while(L + 1 < R && nums[L + 1] == b) 
                        L++;
                    while(L < R - 1 && nums[R - 1] == c)
                        R--;

                    triplets.push_back({a, b, c});
                    L++;
                    R--;
                }
            }

            while(i + 1 < nums.size() && nums[i + 1] == a)
                i++;
        }

        return triplets;
    }
};