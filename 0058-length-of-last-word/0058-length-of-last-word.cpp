class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool mark = false;

        for (int i = s.size() - 1; i >= 0; i--) {
            int encode = int(s[i]);
            if (encode != 32) {
                mark = true;
            }
            if (mark && encode != 32)
                count++;
            if (mark && encode == 32)
                break;
            
        }

        return count;
    }
};