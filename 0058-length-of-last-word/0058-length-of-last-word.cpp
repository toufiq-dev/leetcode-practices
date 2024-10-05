class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int x = (int)s[i];

            if (x != 32) {
                length++;
            } else if (x == 32 and length == 0) {
                continue;
            } else if (x == 32 and length != 0) {
                break;
            }
        }

        return length;
    }
};