class Solution {
public:
    bool isPalindrome(string s) {
        // Create a filtered and lowercase version of the string
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        // Use two pointers to check for palindrome
        int left = 0, right = filtered.size() - 1;
        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};