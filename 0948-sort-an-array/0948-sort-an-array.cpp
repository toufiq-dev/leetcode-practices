class Solution {
public:
    // Function to merge two halves of the array
void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1); // Temporary array for merging
        int i = left;   // Pointer for left half
        int j = mid + 1; // Pointer for right half
        int k = 0;      // Pointer for temp array

        // Merge elements from left and right halves
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        // Copy remaining elements from the left half
        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        // Copy remaining elements from the right half
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        // Copy the sorted elements back to the original array
        for (int p = 0; p < temp.size(); p++) {
            nums[left + p] = temp[p];
        }
    }

    // Recursive function to perform merge sort
void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return; // Base case: single element or invalid range

        int mid = left + (right - left) / 2; // Calculate mid-point

        // Recursively sort the left and right halves
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        // Merge the sorted halves
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};