class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int count = 0;

        if (strs.size() == 1) {
            return strs[0];
        }

        for (int i = 0; i < prefix.size(); i++) {
            bool isPrefix = false;

            for (int j = 1; j < strs.size(); j++) {
                string str = strs[j];
                
                if (prefix[i] != str[i]) {
                    isPrefix = false;
                    break;
                } else {
                    isPrefix = true;
                }
            }
            
            if (isPrefix) {
                count++;
            } else {
                break;
            }
        }

        return prefix.substr(0, count);
    }
};